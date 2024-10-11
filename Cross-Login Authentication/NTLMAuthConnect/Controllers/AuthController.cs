using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

[Authorize] // NTLM authentication applied to the controller
[Route("api/[controller]")]
[ApiController]
public class AuthController : ControllerBase
{
    [HttpPost("login")]
    public IActionResult Login()
    {
        if (User.Identity != null && User.Identity.IsAuthenticated)
        {
            return Ok(new { message = "Authentication successful" });
        }
        return Unauthorized(new { message = "Authentication failed" });
    }
}
