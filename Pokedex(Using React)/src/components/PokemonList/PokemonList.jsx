import * as React from 'react';
import Pokemon from "../Pokemon/Pokemon";
import CircularProgress from '@mui/material/CircularProgress';
import Button from '@mui/material/Button';
import ArrowForwardIosIcon from '@mui/icons-material/ArrowForwardIos';
import ArrowBackIosIcon from '@mui/icons-material/ArrowBackIos';
import './PokemonList.css'
import usePokemonList from "../../hooks/usePokemonList.js";

function PokemonList(){

    const {states, setStates} = usePokemonList();
    
    return(
        <div>
            
            {(states.isLoading) ? <React.Fragment>
      <svg width={0} height={0}>
        <defs>
          <linearGradient id="my_gradient" x1="0%" y1="0%" x2="0%" y2="100%">
            <stop offset="0%" stopColor="#e01cd5" />
            <stop offset="100%" stopColor="#1CB5E0" />
          </linearGradient>
        </defs>
      </svg>
      <CircularProgress sx={{ 'svg circle': { stroke: 'url(#my_gradient)' } }} />
    </React.Fragment> : 
    <div className="pokemonWrapper">
       { states.pokemonList.map((pokemon) => <Pokemon name={pokemon.name} image={pokemon.image} key={pokemon.id} id={pokemon.id} />)}
        </div>
      }
           
            <br /><br />
            <div className="btns">
            <Button variant="contained" startIcon={<ArrowBackIosIcon />} disabled={!states.prev} onClick={()=>{setStates((state)=>({...state, POKEDEX_URL : states.prev}))}}>
                Prev
            </Button>
            <Button variant="contained" endIcon={<ArrowForwardIosIcon />} disabled={!states.next} onClick={()=>{setStates((state)=>({...state, POKEDEX_URL : states.next}))}}>
                Next
            </Button>
            </div>
        </div>
    )
}

export default PokemonList