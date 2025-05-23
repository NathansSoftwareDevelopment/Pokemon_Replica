import pokebase as pb
import json
import requests
from icecream import ic

baseURL = "https://pokeapi.co/api/v2"

outputDictionary = {}

def main():
    firstPokemonID = 1
    lastPokemonID = 649 

    # getPokemonInfo(1)
    printData(parsePokeInfo(getPokemonInfo("Kirlia")))
    # for i in range (35, 36):
    #     printData(parsePokeInfo(getPokemonInfo(i)))
    # addToFinal(getPokemonInfo(1))
    for i in range(firstPokemonID, lastPokemonID+1):
        rawData = getPokemonInfo(i)
        pokeData = parsePokeInfo(rawData)
        addToFinal(pokeData)
    Write(outputDictionary, "Pokemon_Species.json")


def getPokemonInfo(ID):
    pokeURL = f"{baseURL}/pokemon/{ID}"
    rawPokeInfo = requests.get(pokeURL)
    if rawPokeInfo.status_code == 200:
        rawPokemonJSON = rawPokeInfo.json()
        # for i in rawPokemonJSON["abilities"]:
        #     ic(i)
        ic(rawPokemonJSON["species"])
        return rawPokemonJSON
    else:
        print(f"FAILED TO RETRIEVE {ID}: {rawPokeInfo.status_code}")

def getTypes(rawData):
    ic(rawData["past_types"])
    tempTypes = {}
    # set types to current types
    tempTypes[1] = rawData["types"][0]["type"]["name"]
    if len(rawData["types"]) > 1:
        tempTypes[2] = rawData["types"][1]["type"]["name"]
    else:
        tempTypes[2] = "none"
    # check each time a typing has changed
    for i in rawData["past_types"]:
        # if the typing changed in generation 6 (from the typing in generation 5) use the generation 5 types.
        # it should be noted that no typing has changed since generation 6
        if i["generation"]["name"] == "generation-v":
            tempTypes[1] = i["types"][0]["type"]["name"]
            if len(i["types"]) > 1:
                tempTypes[2] = i["types"][1]["type"]["name"]
    return tempTypes

def printData(inputDictionary):
    ic(inputDictionary)

def parsePokeInfo(rawData):
    pokeData = {}

    pokeData["name"] = rawData["name"]

    tempStats = {}
    for i in range (6):
        tempStats[rawData["stats"][i]["stat"]["name"]] = rawData["stats"][i]["base_stat"]
    pokeData["stats"] = tempStats

    pokeData["types"] = getTypes(rawData)
    # ic(rawData["past_types"])

    # populate tempAbilities with abilities slots and types
    tempAbilities = {}
    for i in rawData["abilities"]:
        tempAbilities[i["slot"]] = i["ability"]["name"]
    # if ability slots 1 or 2 are missing replace with "None"
    tempAbilities[2] = tempAbilities.get(2, "None")
    tempAbilities[3] = tempAbilities.get(3, "None")

    pokeData["abilities"] = tempAbilities

    # get the species of pokemon, get the evolution chain of that species, then access "chain" key
    evolutionChain = requests.get(requests.get(rawData["species"]["url"]).json()["evolution_chain"]["url"]).json()["chain"]
    try:
        # if first pokemon name == name of pokemon | evolve = second pokemon
        if evolutionChain["species"]["name"] == pokeData["name"]:
            if len(evolutionChain["evolves_to"]) <= 1:
                pokeData["evolve"] = evolutionChain["evolves_to"][0]["species"]["name"]
            else:
                pokeData["evolve"] = "special"
        # if second pokemon name == name of pokemon | evolve = third pokemon
        elif evolutionChain["evolves_to"][0]["species"]["name"] == pokeData["name"]:
            if len(evolutionChain["evolves_to"][0]["evolves_to"]) <= 1:
                pokeData["evolve"] = evolutionChain["evolves_to"][0]["evolves_to"][0]["species"]["name"]
            else:
                pokeData["evolve"] = "special"
        # otherwise | evolve = name of pokemon
        else:
            pokeData["evolve"] = pokeData["name"]
    except IndexError:
        # For single stage pokemon evolutionChain["evolves_to"] will be an empty array causing an error
        pokeData["evolve"] = pokeData["name"]
    
    print(f"evolutionChain[\"species\"][\"name\"] = {evolutionChain["species"]["name"]}\npokeData[\"name\"] = {pokeData["name"]}")
    # ic(evolutionChain["evolves_to"][0]["evolves_to"][1]["species"]["name"])

    return pokeData


def addToFinal(inputDictionary):
    outputDictionary[inputDictionary["name"]] = inputDictionary

def Write(Object, FileName):
    json_string = json.dumps(Object, indent=4)
    with open(FileName, 'w') as f:
        f.write(json_string)

if __name__ == "__main__":
    main()