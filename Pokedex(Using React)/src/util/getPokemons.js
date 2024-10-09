import axios from "axios";

async function getPokemons(states, setStates){
    setStates((state)=>({...state, isLoading : true}))
    const response = await axios.get(states.POKEDEX_URL); //Download list of pokemons
    setStates((state)=>({...state, prev:response.data.previous, next:response.data.next}));
    const responseData = response.data.results; //Array of downloaded pokemons
    const responseResults = responseData.map((pokemon)=>axios.get(pokemon.url));
    const pokemonResults = await axios.all(responseResults);
    const res = pokemonResults.map((pokeData)=>{
        return{
            id: pokeData.data.id,
            name: pokeData.data.name.toUpperCase(),
            image: pokeData.data.sprites.other.dream_world.front_default,
            type: pokeData.data.types
        }
    });
    setStates((state)=>({...state, isLoading : false, pokemonList:res}));
}

export default getPokemons;