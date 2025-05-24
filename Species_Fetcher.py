import pokebase as pb
import json
import requests
from icecream import ic

baseURL = "https://pokeapi.co/api/v2"

outputDictionary = {}

def main():
    firstPokemonID = 1
    lastPokemonID = 649 

    # printFinalData(parsePokeInfo(getPokemonInfo("lillipup")))
    for i in range(firstPokemonID, lastPokemonID+1):
        rawData = getPokemonInfo(i)
        pokeData = parsePokeInfo(rawData)
        addToFinal(pokeData)
    Write(outputDictionary, "Pokemon_Species.json")


def getPokemonInfo(ID):
    pokemonURL = f"{baseURL}/pokemon/{ID}"
    speciesURL = f"{baseURL}/pokemon-species/{ID}"
    rawPokemonInfo = requests.get(pokemonURL)
    rawSpeciesInfo = requests.get(speciesURL)
    if rawPokemonInfo.status_code == 200 & rawSpeciesInfo.status_code == 200:
        rawPokemonInfo = rawPokemonInfo.json()
        rawSpeciesInfo = rawSpeciesInfo.json()
        print(f"Found {ID}: {rawSpeciesInfo["name"]}")
        return [rawPokemonInfo, rawSpeciesInfo]
    else:
        print(f"FAILED TO RETRIEVE {ID}: {rawPokemonInfo.status_code} | {rawSpeciesInfo.status_code}")

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
        # if the last change was before gen 5 | use the most recent information
        if max(generationChanges) < 5:
            correctGeneration = max(generationChanges)
        # if 5 is a valid generation | correctGeneration = 5
        elif 5 in generationChanges:
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
    ic(tempAbilities)
    return tempAbilities

def getEvolve(rawSpeciesData, pokemonName):
    # get the species of pokemon, get the evolution chain of that species, then access "chain" key
    evolutionChain = requests.get(rawSpeciesData["evolution_chain"]["url"]).json()["chain"]
    try:
        # if first pokemon name == name of pokemon | evolve = second pokemon
        if evolutionChain["species"]["name"] == pokemonName:
            if len(evolutionChain["evolves_to"]) <= 1:
                evolution = evolutionChain["evolves_to"][0]["species"]["name"]
            else:
                evolution = "special"
        # if second pokemon name == name of pokemon | evolve = third pokemon
        elif evolutionChain["evolves_to"][0]["species"]["name"] == pokemonName:
            if len(evolutionChain["evolves_to"][0]["evolves_to"]) <= 1:
                evolution = evolutionChain["evolves_to"][0]["evolves_to"][0]["species"]["name"]
            else:
                evolution = "special"
        # otherwise | evolve = name of pokemon
        else:
            evolution = pokemonName
    except IndexError:
        # For single stage pokemon evolutionChain["evolves_to"] will be an empty array causing an error
        evolution = pokemonName
    return evolution


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
    for i in range (6):
        tempStats[rawPokemonData["stats"][i]["stat"]["name"]] = rawPokemonData["stats"][i]["base_stat"]
    pokeData["stats"] = tempStats

    pokeData["types"] = getTypes(rawPokemonData)

    pokeData["abilities"] = getAbilities(rawPokemonData)

    pokeData["evolve"] = getEvolve(rawSpeciesData, pokeData["name"])
    
    return pokeData


def addToFinal(inputDictionary):
    outputDictionary[inputDictionary["name"]] = inputDictionary

def Write(Object, FileName):
    json_string = json.dumps(Object, indent=4)
    with open(FileName, 'w') as f:
        f.write(json_string)

if __name__ == "__main__":
    main()