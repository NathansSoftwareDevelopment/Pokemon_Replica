import json

from icecream import ic


def main():
    rawMoveData = {}
    rawMoveData = getMoveInfo()
    allMoveData = {}
    for moveName in rawMoveData:
        moveData = parseMoveInfo(rawMoveData[moveName][0])
        allMoveData[moveData["name"]] = moveData
    Write(allMoveData, r"Move.json")

def getMoveInfo():
    URL = r"./Raw_Data/Raw_Move_Data.json"
    Raw_Move_Data = {}
    with open(URL, 'r', encoding='utf-8') as f:
        Raw_Move_Data = json.load(f)
    return Raw_Move_Data

def getVersionValues(inputMove):

    # Find all potentially relevant times the move's data changed
    versionsList = []
    versionsDict = {}
    for version in inputMove["past_values"]:
        # Find the version number in the URL (if there's a single digit number then make it a double digit)
        versionGroupNumber = int(version["version_group"]["url"][-3:-1].replace("/", "0"))
        if versionGroupNumber >= 15:
            versionsList.append(versionGroupNumber)
        # Add the version number and data from the given version to a dict
        versionsDict[versionGroupNumber] = version
    
    # Identify the correct change to use (None if the current data is correct)
    # Find the minimum value in verionsList >= 15
    correctVersion = min([versionNumber for versionNumber in versionsList if versionNumber >= 15], default=None)
    versionValues = {}
    if correctVersion is not None:
        for key, value in versionsDict[correctVersion].items():
            if key in ["effect_chance", "effect_entries", "version_group"]:
                pass
            elif value is None:
                pass
            elif key == "pp":
                versionValues["PP"] = value
            elif key == "type":
                versionValues["type"] = value["name"].capitalize()
            else:
                versionValues[key] = value
    return versionValues

def parseMoveInfo(inputMove):
    moveData = {}

    # The naming scheme of PokeAPI is destructive in nature so several move names had to be manually respecified
    hyphenatedDict = {"double-edge": "Double-Edge", "freeze-dry": "Freeze-Dry", "lock-on": "Lock-On", "mud-slap": "Mud-Slap", "power-up-punch": "Power-Up Punch",
                      "self-destruct": "Self-Destruct", "soft-boiled": "Soft-Boiled", "u-turn": "U-turn", "v-create": "V-create", "wake-up-slap": "Wake-Up Slap",
                      "will-o-wisp": "Will-O-Wisp", "x-scissor": "X-Scissor"}
    if inputMove["name"] in hyphenatedDict.keys():
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
    
    if inputMove["accuracy"] is None:
        moveData["accuracy"] = 0
    else:
        moveData["accuracy"] = inputMove["accuracy"]

    moveData["PP"] = inputMove["pp"]

    moveData.update(getVersionValues(inputMove))

    moveData["flinchChance"] = inputMove["meta"]["flinch_chance"]
    ic(moveData)
    return moveData

def Write(allMoveData, fileName):
    json_string = json.dumps(allMoveData, indent=4)
    with open(fileName, 'w') as f:
        f.write(json_string)


if __name__ == "__main__":
    main()