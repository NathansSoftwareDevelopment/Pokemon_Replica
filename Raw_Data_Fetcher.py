import pokebase as pb
import json
import requests
from icecream import ic
import itertools as it


outputDictionary = {}

def main():
    firstPokemonID = 1
    lastPokemonID = 649
    firstVarietyID = 10001 
    lastVarietyID = 10023 
    baseURL = "https://pokeapi.co/api/v2/"

    dataType = input("What type of data to get? ")

    if dataType == "pokemon":
        for i in it.chain(range(firstPokemonID, lastPokemonID+1), range(firstVarietyID, lastVarietyID+1)):
            addToFinal(dataType, getPokemonInfo(baseURL + dataType+"/", i))
    
    elif dataType == "pokemon-species":
        for i in range(firstPokemonID, lastPokemonID+1):
            addToFinal(dataType, getPokemonInfo(baseURL + dataType+"/", i))
    
    if dataType == "evolution-chain":
        with open("Raw_Data/Raw_Pokemon_Data.json", "r") as f:
            rawPokemonData = json.load(f)
        with open("Raw_Data/Raw_Pokemon-species_Data.json", "r") as f:
            rawSpeciesData = json.load(f)
        for specieName, speciesData in rawSpeciesData.items():
            ic(specieName)
            if speciesData:
                speciesInfo = speciesData[0]
                evolutionChainURL = speciesInfo["evolution_chain"]["url"]
                for variety in speciesInfo["varieties"]:
                    pokemonName = variety["pokemon"]["name"]
                    # if pokemon is in rawPokemonData and has valid data | add to output dictionary
                    if pokemonName in rawPokemonData and rawPokemonData[pokemonName]:
                        addToFinal(dataType, getEvolutionInfo(evolutionChainURL, pokemonName))
    
    if dataType == "growth-rate":
        for i in range(1, 6+1):
            addToFinal(dataType, getGrowthRateInfo(i))
    
    if dataType == "move":
        for i in range(1, 559+1):
            addToFinal(dataType, getPokemonInfo(baseURL + dataType+"/", 1))


    Write(outputDictionary, f"Raw_Data/Raw_{dataType.capitalize()}_Data.json")


def getPokemonInfo(dataType, ID):
    URL = dataType + str(ID)
    rawData = requests.get(URL)
    if rawData.status_code == 200:
        rawData = rawData.json()
        print(f"Found {dataType[:-1]} ID: {ID} | {rawData["name"]}")
        return [rawData]
    else:
        print(f"FAILED TO RETRIEVE {dataType[:-1]} ID: {ID} | {rawData.status_code}")

def getEvolutionInfo(evolutionChainURL, pokemonName):
    ic(evolutionChainURL)
    # get the species of pokemon, get the evolution chain of that species, then access "chain" key
    evolutionChain = requests.get(evolutionChainURL).json()["chain"]
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
    return {pokemonName: evolution}

def getGrowthRateInfo(ID):
    URL = f"https://pokeapi.co/api/v2/growth-rate/{ID}"
    rawData = requests.get(URL)
    if rawData.status_code == 200:
        rawData = rawData.json()
        print(f"Found Growth-Rate {ID}: {rawData["name"]}")
        return rawData
    else:
        print(f"FAILED TO RETRIEVE GROWTH-RATE: {ID}")

def addToFinal(dataType, inputDictionary):
    if dataType in ["pokemon", "pokemon-species", "move"]:
        outputDictionary[inputDictionary[0]["name"]] = inputDictionary
    if dataType == "evolution-chain":
        outputDictionary[list(inputDictionary.keys())[0]] = list(inputDictionary.values())[0]
    if dataType == "growth-rate":
        outputDictionary[inputDictionary["name"]] = inputDictionary


def Write(Object, FileName):
    json_string = json.dumps(Object, indent=4)
    with open(FileName, 'w') as f:
        f.write(json_string)

if __name__ == "__main__":
    main()