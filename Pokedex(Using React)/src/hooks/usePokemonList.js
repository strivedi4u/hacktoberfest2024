import { useEffect, useState } from "react";
import getPokemons from "../util/getPokemons.js";

function usePokemonList(){
    const [states, setStates] = useState({
        pokemonList: [null],
        isLoading: true,
        prev: null,
        next: null,
        POKEDEX_URL:'https://pokeapi.co/api/v2/pokemon'
    })
    
    useEffect(()=>{
        getPokemons(states, setStates)
    }, [states.POKEDEX_URL])

    return {states, setStates};
}

export default usePokemonList