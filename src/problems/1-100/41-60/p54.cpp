#include "problems/problem_registry.hpp"
#include "math/io.hpp"

#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <sstream>

namespace poker {

enum Suit
{
    Hearts,
    Diamonds,
    Spades,
    Clubs
};

enum Value
{
    Two,
    Three,
    Four,
    Five,
    Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
};

enum Rank
{
    Unranked,
    HighCard,
    OnePair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush,
};

struct Card
{
    Suit suit;
    Value value;
};

struct Hand
{
    std::vector<Card> cards;
    Rank rank;
    Value low;
    Value high;
};

Card fromString(std::string &str)
{
    Card card;
    switch(str[0])
    {
        default:
        case '2': card.value = Two; break;
        case '3': card.value = Three; break;
        case '4': card.value = Four; break;
        case '5': card.value = Five; break;
        case '6': card.value = Six; break;
        case '7': card.value = Seven; break;
        case '8': card.value = Eight; break;
        case '9': card.value = Nine; break;
        case 'T': card.value = Ten; break;
        case 'J': card.value = Jack; break;
        case 'Q': card.value = Queen; break;
        case 'K': card.value = King; break;
        case 'A': card.value = Ace; break;
    }
    switch(str[1]) {
        case 'H': card.suit = Hearts; break;
        case 'D': card.suit = Diamonds; break;
        case 'S': card.suit = Spades; break;
        case 'C': card.suit = Clubs; break;
    }
    return card;
}

std::tuple<Hand, Hand> readHands(std::string line)
{
    std::stringstream sstr(line);
    std::string cardString;
    Hand hand1;
    for(size_t i = 0; i < 5; ++i) {
        sstr >> cardString;
        Card card = fromString(cardString);
        hand1.cards.push_back(card);
    }
    Hand hand2;
    for(size_t i = 0; i < 5; ++i) {
        sstr >> cardString;
        Card card = fromString(cardString);
        hand2.cards.push_back(card);
    }
    return {hand1, hand2};
}

bool compareCards(const Card &lhs, const Card &rhs)
{
    return lhs.value < rhs.value;
}

bool isFourOfAKind(Hand &hand)
{
    if((hand.cards[0].value == hand.cards[1].value
        && hand.cards[1].value == hand.cards[2].value
        && hand.cards[2].value == hand.cards[3].value)
       || (hand.cards[1].value == hand.cards[2].value
           && hand.cards[2].value == hand.cards[3].value
           && hand.cards[3].value == hand.cards[4].value)) {
        hand.high = hand.cards[1].value;
        return true;
    }
    return false;
}

bool isThreeOfAKind(Hand &hand)
{
    if((hand.cards[0].value == hand.cards[1].value
        && hand.cards[1].value == hand.cards[2].value)
       || (hand.cards[1].value == hand.cards[2].value
           && hand.cards[2].value == hand.cards[3].value)
       || (hand.cards[2].value == hand.cards[3].value
           && hand.cards[3].value == hand.cards[4].value)) {
        hand.high = hand.cards[2].value;
        return true;
    }
    return false;
}

bool isTwoPair(Hand &hand)
{
    if(hand.cards[0].value == hand.cards[1].value
       && hand.cards[2].value == hand.cards[3].value) {
        hand.low = hand.cards[0].value;
        hand.high = hand.cards[2].value;
        return true;
    } else if(hand.cards[0].value == hand.cards[1].value
              && hand.cards[3].value == hand.cards[4].value) {
        hand.low = hand.cards[0].value;
        hand.high = hand.cards[3].value;
        return true;
    } else if(hand.cards[1].value == hand.cards[2].value
              && hand.cards[3].value == hand.cards[4].value) {
        hand.low = hand.cards[1].value;
        hand.high = hand.cards[3].value;
        return true;
    }
    return false;
}

bool isPair(Hand &hand)
{
    if(hand.cards[0].value == hand.cards[1].value) {
        hand.high = hand.cards[0].value;
        return true;
    } else if(hand.cards[1].value == hand.cards[2].value) {
        hand.high = hand.cards[1].value;
        return true;
    } else if(hand.cards[2].value == hand.cards[3].value) {
        hand.high = hand.cards[2].value;
        return true;
    } else if(hand.cards[3].value == hand.cards[4].value) {
        hand.high = hand.cards[3].value;
        return true;
    }
    return false;
}

bool isFullHouse(Hand &hand)
{
    if(hand.cards[0].value == hand.cards[1].value
       && hand.cards[1].value == hand.cards[2].value
       && hand.cards[3].value == hand.cards[4].value) {
        hand.high = hand.cards[0].value;
        hand.low = hand.cards[3].value;
        return true;
    } else if(hand.cards[0].value == hand.cards[1].value
              && hand.cards[2].value == hand.cards[3].value
              && hand.cards[3].value == hand.cards[4].value) {
        hand.high = hand.cards[0].value;
        hand.low = hand.cards[2].value;
        return true;
    }
    return false;
}

bool isStraight(const Hand &hand)
{
    if(hand.cards[0].value == Two
       && hand.cards[1].value == Three
       && hand.cards[2].value == Four
       && hand.cards[3].value == Five
       && hand.cards[4].value == Ace) {
        return true;
    }

    for(size_t i = 1; i < 5; ++i) {
        if(hand.cards[i].value != hand.cards[i - 1].value + 1) {
            return false;
        }
    }

    return true;
}

bool isFlush(const Hand &hand)
{
    return (hand.cards[0].suit == hand.cards[1].suit
            && hand.cards[1].suit == hand.cards[2].suit
            && hand.cards[2].suit == hand.cards[3].suit
            && hand.cards[3].suit == hand.cards[4].suit);
}

void rank(Hand &hand)
{
    // Sort hand
    std::sort(hand.cards.begin(), 
              hand.cards.end(),
              compareCards);

    if(isFlush(hand) && isStraight(hand)) {
        if(hand.cards[4].value == Ace) {
            hand.rank = RoyalFlush;
        } else {
            hand.rank = StraightFlush;
        }
    } else if(isFourOfAKind(hand)) {
        hand.rank = FourOfAKind;
    } else if(isFullHouse(hand)) {
        hand.rank = FullHouse;
    } else if(isFlush(hand)) {
        hand.rank = Flush;
    } else if(isStraight(hand)) {
        hand.rank = Straight;
    } else if(isThreeOfAKind(hand)) {
        hand.rank = ThreeOfAKind;
    } else if(isTwoPair(hand)) {
        hand.rank = TwoPair;
    } else if(isPair(hand)) {
        hand.rank = OnePair;
    } else {
        hand.rank = HighCard;
    }
}

int compare(Hand &hand1, Hand &hand2)
{
    if(hand1.rank > hand2.rank) {
        return 1;
    } else if(hand1.rank < hand2.rank) {
        return -1;
    } else {
        if(hand1.rank == OnePair || hand1.rank == ThreeOfAKind || hand1.rank == FourOfAKind) {
            if(hand1.high > hand2.high) {
                return 1;
            } else if(hand1.high < hand2.high) {
                return -1;
            }
        } else if(hand1.rank == TwoPair || hand1.rank == FullHouse) {
            if(hand1.high > hand2.high) {
                return 1;
            } else if(hand1.high < hand2.high) {
                return -1;
            } else {
                if(hand1.low > hand2.low) {
                    return 1;
                } else if(hand1.low < hand2.low) {
                    return -1;
                }
            }
        }

        for(int i = 4; i >= 0; --i) {
            if(hand1.cards[i].value > hand2.cards[i].value) {
                return 1;
            } else if(hand1.cards[i].value < hand2.cards[i].value) {
                return - 1;
            }
        }
    }
    return 0;
}

int compareHands(Hand &hand1, Hand &hand2)
{
    rank(hand1);
    rank(hand2);

    return compare(hand1, hand2);
}

} // namespace poker

int64_t problem_54()
{
    std::string fileContent = pe::readFile("data/p54_poker.txt");
    std::stringstream sstr;
    sstr.str(fileContent);
    std::string line;
    int wins[3]{0};
    while(std::getline(sstr, line)) {
        auto [hand1, hand2] = poker::readHands(line);
        int result = poker::compareHands(hand1, hand2);
        wins[result + 1]++;
    }
    
    return wins[2];
}

REGISTER_FUNCTION(54, problem_54);
