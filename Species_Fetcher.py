import pokebase as pb
import json
import requests
from icecream import ic

outputDictionary = {}

def main():
    rawPokemonData = r"./Raw_Data/Raw_Pokemon_Data.json"
    rawSpeciesData = r"./Raw_Data/Raw_Pokemon-species_Data.json"

    allRawData = getPokemonInfo(rawPokemonData, rawSpeciesData)
    for pokemon in allRawData[0]:
        pokemonName = allRawData[0][pokemon][0]
        addToFinal(parsePokeInfo([allRawData[0][pokemonName["name"]][0], allRawData[-1][pokemonName["species"]["name"]][0]]))
        ic(pokemonName["name"])
    Write(outputDictionary, "Species.json")


def getPokemonInfo(*args):
    with open(args[0], 'r') as file1:
        dict1 = json.load(file1)
    with open(args[-1], 'r') as file2:
        dict2 = json.load(file2)
    return [dict1, dict2]

def getTypes(rawData):
    tempTypes = {}
    
    # set types to current types
    tempTypes[1] = rawData["types"][0]["type"]["name"]
    tempTypes[2] = rawData["types"][1]["type"]["name"] if len(rawData["types"]) > 1 else "none"

    # generations use roman numerals. This map will allow for the an easy conversion and comparison
    # additional characters are added the front of numerals so that all numerals are four characters (to match with generation-#)
    romanDict = {
        'on-i': 1, 'n-ii': 2, '-iii': 3, 'n-iv': 4, 'on-v': 5,
        'n-vi': 6, '-vii': 7, 'viii': 8, 'n-ix': 9
    }

    generationChanges = []

    # check each time a typing has changed
    for i in rawData["past_types"]:
        generationChanges.append(romanDict[i["generation"]["name"][-4:]])
    # identify the correct generation
    correctGeneration = 100
    # if there were relevent changes | change to the correct typing
    if generationChanges:
        # if the last change was before or at gen 5 | use either the most information for gen 5 or none at all (causing the types to not change)
        if max(generationChanges) <= 5:
            correctGeneration = 5
        # if there was a change past gen 5 | use the lowest generation past gen 5
        elif max(generationChanges) > 5:
            for i in generationChanges:
                if i < correctGeneration & i > 5:
                    correctGeneration = i
    # use the correct generation data
    for i in rawData["past_types"]:
        if romanDict[i["generation"]["name"][-4:]] == correctGeneration:
            tempTypes[1] = i["types"][0]["type"]["name"]
            tempTypes[2] = i["types"][1]["type"]["name"] if len(i["types"]) > 1 else "none"

    return tempTypes

def getAbilities(rawPokemonData):
    # populate tempAbilities with modern slots and abilities
    tempAbilities = {item["slot"]: item["ability"]["name"] for item in rawPokemonData.get("abilities", [])}
    # if ability slots 2 or 3 are missing replace with "None"
    tempAbilities[2] = tempAbilities.get(2, "none")
    tempAbilities[3] = tempAbilities.get(3, "none")

    # generations use roman numerals. This map will allow for the an easy conversion and comparison
    # additional characters are added the front of numerals so that all numerals are four characters (to match with generation-#)
    romanDict = {
        'on-i': 1, 'n-ii': 2, '-iii': 3, 'n-iv': 4, 'on-v': 5,
        'n-vi': 6, '-vii': 7, 'viii': 8, 'n-ix': 9
    }

    generationChanges = []
    # check each time abilities have changed
    for i in rawPokemonData["past_abilities"]:
        generationChanges.append(romanDict[i["generation"]["name"][-4:]])
    
    # identify the correct generation
    correctGeneration = 100
    # if there were relevent changes | change to the correct abilities
    if generationChanges:
        # if the last change was before or at gen 5 | use either the most information for gen 5 or none at all (causing the abilities to not change)
        if max(generationChanges) <= 5:
            correctGeneration = 5
        # if there was a change past gen 5 | use the lowest generation past gen 5
        elif max(generationChanges) > 5:
            for i in generationChanges:
                if i < correctGeneration & i > 5:
                    correctGeneration = i
    
    # use the correct generation data
    for i in rawPokemonData["past_abilities"]:
        if romanDict[i["generation"]["name"][-4:]] == correctGeneration:
            # replace each ability slot that has changed with its respective ability
            tempAbilities.update({ability["slot"]: ability["ability"]["name"] if ability["ability"] is not None else "none" for ability in i["abilities"]})

    return tempAbilities

def getEvolve(pokemonName):
    with open("Raw_Data/Evolution_Table.json", "r") as f:
        evolutionTable = json.load(f)
        return evolutionTable[pokemonName]

def printFinalData(finalData):
    for i in finalData:
        print(i)
        print(finalData[i])

def printRawData(rawData):
    for i in rawData:
        print(i)
    print()

def parsePokeInfo(rawData):
    rawPokemonData = rawData[0]
    rawSpeciesData = rawData[1]
    # printRawData(rawPokemonData)
    # printRawData(rawSpeciesData)
    pokeData = {}

    pokeData["name"] = rawPokemonData["name"]

    tempStats = {}
    for i in range(6):
        tempStats[rawPokemonData["stats"][i]["stat"]["name"]] = rawPokemonData["stats"][i]["base_stat"]
    pokeData["stats"] = tempStats

    pokeData["types"] = getTypes(rawPokemonData)

    pokeData["abilities"] = getAbilities(rawPokemonData)

    pokeData["evolve"] = getEvolve(pokeData["name"])

    pokeData["growth-rate"] = rawSpeciesData["growth_rate"]["name"]

    pokeData["base-experience"] = rawPokemonData["base_experience"]

    tempEVs = {}
    for i in rawPokemonData["stats"]:
        tempEVs[i["stat"]["name"]] = i["effort"]
    pokeData["effort-values"] = tempEVs


    return pokeData


def addToFinal(inputDictionary):
    outputDictionary[inputDictionary["name"]] = inputDictionary

def Write(Object, FileName):
    json_string = json.dumps(Object, indent=4)
    with open(FileName, 'w') as f:
        f.write(json_string)

if __name__ == "__main__":
    main()