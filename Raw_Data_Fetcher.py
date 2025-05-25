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
    if dataType in ["pokemon", "pokemon-species"]:
        for i in it.chain(range(firstPokemonID, lastPokemonID+1), range(firstVarietyID, lastVarietyID+1)):
            addToFinal(getPokemonInfo(baseURL + dataType+"/", i))
    Write(outputDictionary, f"Raw_Data/Raw_{dataType.capitalize()}_Data.json")
    pass


def getPokemonInfo(dataType, ID):
    URL = dataType + str(ID)
    rawData = requests.get(URL)
    if rawData.status_code == 200:
        rawData = rawData.json()
        print(f"Found {dataType[:-1]} ID: {ID} | {rawData["name"]}")
        return [rawData]
    else:
        print(f"FAILED TO RETRIEVE {dataType[:-1]} ID: {ID} | {rawData.status_code}")

def addToFinal(inputDictionary: dict):
    outputDictionary[inputDictionary[0]["name"]] = inputDictionary

def Write(Object, FileName):
    json_string = json.dumps(Object, indent=4)
    with open(FileName, 'w') as f:
        f.write(json_string)

if __name__ == "__main__":
    main()