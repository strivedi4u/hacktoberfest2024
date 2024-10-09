import { useState } from "react";
import PokemonList from "../PokemonList/PokemonList";
import Search from "../Search/Search";
import "./Pokedex.css"
import PokemonDetails from '../PokemonDetails/PokemonDetails';

function Pokedex() {
    const [searchTerm, setSearchTerm] = useState('');
    return(
        <div className="pokedex">
            <Search updateSearchTerm={setSearchTerm}/>
            {searchTerm ? <PokemonDetails pokemonName={searchTerm}/> : <PokemonList />}
        </div>
    )
}

export default Pokedex;