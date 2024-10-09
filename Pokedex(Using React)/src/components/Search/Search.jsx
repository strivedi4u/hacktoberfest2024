import TextField from '@mui/material/TextField';
import useDebounce from '../../hooks/useDebounce.js';

function Search({ updateSearchTerm }){
    const debounceUpdateSearch = useDebounce((e) => updateSearchTerm(e.target.value));
    return(
        <>
            <TextField
            style={{width:"500px", marginBottom:"50px"}}
          label="Pokemon"
          id="outlined-size-small"
          size="small"
          color="secondary" 
          onChange={debounceUpdateSearch}
        />
        </>
    )
}

export default Search;