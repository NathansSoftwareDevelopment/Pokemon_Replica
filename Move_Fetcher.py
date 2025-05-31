import json
from icecream import ic


def main():
    rawMoveData = {}
    rawMoveData = getMoveInfo()
    for moveName in rawMoveData:
        parseMoveInfo(rawMoveData[moveName])

def getMoveInfo():
    URL = r"./Raw_Data/temp_moves.json"
    Raw_Move_Data = {}
    with open(URL, 'r', encoding='utf-8') as f:
        Raw_Move_Data = json.load(f)
    return Raw_Move_Data

def parseMoveInfo(inputMove):
    moveData = {}

    # The naming scheme of PokeAPI is destructive in nature so several move names had to be manually respecified
    hyphenatedDict = {"double-edge": "Double-Edge", "freeze-dry": "Freeze-Dry", "lock-on": "Lock-On", "mud-slap": "Mud-Slap", "power-up-punch": "Power-Up Punch",
                      "self-destruct": "Self-Destruct", "soft-boiled": "Soft-Boiled", "u-turn": "U-turn", "v-create": "V-create", "wake-up-slap": "Wake-Up Slap",
                      "will-o-wisp": "Will-O-Wisp", "x-scissor": "X-Scissor"}
    if inputMove["name"] in hyphenatedDict.values():
        moveData["name"] = hyphenatedDict[inputMove["name"]]
    else:
        # If the move name did not have to be manually respecified | Capitalize all words in move name and replace the hyphens with spaces
        moveData["name"] = " ".join([word.capitalize() for word in inputMove["name"].split("-")])

    moveData["type"] = inputMove["type"]["name"].capitalize()

    moveData["damageCategory"] = inputMove["damage_class"]["name"].capitalize()

    if inputMove["power"] is None:
        moveData["power"] = 0
    else:
        moveData["power"] = inputMove["power"]
    
    moveData["accuracy"] = inputMove["accuracy"]

    moveData["PP"] = inputMove["pp"]

    moveData["flinchChance"] = inputMove["meta"]["flinch_chance"]
    ic(moveData)


if __name__ == "__main__":
    main()