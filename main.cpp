// Manchester United website generator
// Build:  g++ -std=c++17 main.cpp -o mu_site
// Run:    ./mu_site      -> creates index.html, history.html, stadium.html, honours.html, style.css
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Page {
    std::string file, title;
};

const std::vector<Page> PAGES = {
    {"index.html", "Home"},
    {"history.html", "History"},
    {"stadium.html", "Old Trafford"},
    {"honours.html", "Honours"},
};

// Image block: put your own pictures in the "images" folder.
// If a file is missing, a red placeholder box with the caption is shown instead.
std::string picture(const std::string& file, const std::string& caption) {
    return "<figure class=\"pic\"><img src=\"images/" + file + "\" alt=\"" + caption +
           "\" onerror=\"this.parentElement.classList.add('missing');this.remove()\">"
           "<figcaption>" + caption + "</figcaption></figure>\n";
}

std::string layout(const Page& current, const std::string& body) {
    std::string nav;
    for (const auto& p : PAGES) {
        nav += "<a href=\"" + p.file + "\"" + (p.file == current.file ? " class=\"active\"" : "") +
               ">" + p.title + "</a>";
    }
    return "<!DOCTYPE html>\n<html lang=\"en\"><head><meta charset=\"utf-8\">\n"
           "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
           "<title>" + current.title + " | Manchester United Fan Site</title>\n"
           "<link rel=\"stylesheet\" href=\"style.css\"></head><body>\n"
           "<header><div class=\"brand\">MANCHESTER UNITED</div><nav>" + nav + "</nav></header>\n"
           "<main>\n" + body + "</main>\n"
           "<footer>Unofficial fan website &middot; Glory Glory Man United</footer>\n"
           "</body></html>\n";
}

void write(const std::string& name, const std::string& content) {
    std::ofstream out(name);
    out << content;
    std::cout << "Created " << name << "\n";
}

int main() {
    // ---------- CSS ----------
    write("style.css", R"(
:root{--red:#da291c;--dark:#1a1a1a;--gold:#fbe122;--bg:#f5f5f5}
*{box-sizing:border-box}
body{margin:0;font-family:Segoe UI,Arial,sans-serif;background:var(--bg);color:var(--dark);line-height:1.6}
header{background:var(--red);display:flex;flex-wrap:wrap;align-items:center;justify-content:space-between;padding:12px 24px;position:sticky;top:0}
.brand{color:#fff;font-weight:800;letter-spacing:2px;font-size:1.3rem}
nav a{color:#fff;text-decoration:none;margin-left:18px;padding:6px 2px;font-weight:600;border-bottom:3px solid transparent}
nav a:hover,nav a.active{border-bottom-color:var(--gold)}
main{max-width:960px;margin:0 auto;padding:24px 16px}
.hero{background:var(--dark);color:#fff;padding:48px 24px;border-radius:10px;text-align:center;border-bottom:6px solid var(--red)}
.hero h1{margin:0 0 8px;font-size:2.2rem}.hero p{color:#ddd;margin:0}
.facts{display:grid;grid-template-columns:repeat(auto-fit,minmax(200px,1fr));gap:12px;margin:24px 0}
.fact{background:#fff;border-left:5px solid var(--red);padding:12px 16px;border-radius:6px}
.fact b{display:block;color:var(--red)}
.gallery{display:grid;grid-template-columns:repeat(auto-fit,minmax(260px,1fr));gap:16px;margin:24px 0}
.pic{margin:0;background:#fff;border-radius:8px;overflow:hidden;box-shadow:0 1px 4px #0002}
.pic img{width:100%;height:200px;object-fit:cover;display:block}
.pic figcaption{padding:8px 12px;font-size:.9rem;color:#555}
.pic.missing::before{content:"Add image to /images";display:flex;align-items:center;justify-content:center;height:200px;background:repeating-linear-gradient(45deg,#da291c,#da291c 12px,#c0241a 12px,#c0241a 24px);color:#fff;font-weight:600}
h2{border-left:6px solid var(--red);padding-left:10px}
table{width:100%;border-collapse:collapse;background:#fff;border-radius:8px;overflow:hidden}
th{background:var(--dark);color:#fff;text-align:left}th,td{padding:10px 14px}
tr:nth-child(even){background:#f0f0f0}
.timeline{border-left:4px solid var(--red);padding-left:18px}
.timeline p{margin:0 0 14px}.timeline b{color:var(--red)}
.btn{display:inline-block;margin-top:16px;background:var(--red);color:#fff;padding:10px 20px;border-radius:6px;text-decoration:none;font-weight:700}
footer{text-align:center;padding:24px;color:#777;font-size:.9rem}
@media(max-width:600px){nav a{margin:0 10px 0 0}}
)");

    // ---------- Home ----------
    write(PAGES[0].file, layout(PAGES[0], R"(
<section class="hero"><h1>Manchester United Football Club</h1>
<p>The Red Devils &mdash; one of the most successful clubs in English football</p>
<a class="btn" href="history.html">Explore our history</a></section>
<h2>Club at a glance</h2>
<div class="facts">
<div class="fact"><b>Founded</b>1878 as Newton Heath LYR F.C.</div>
<div class="fact"><b>Renamed</b>Manchester United in 1902</div>
<div class="fact"><b>Nickname</b>The Red Devils</div>
<div class="fact"><b>Home ground</b>Old Trafford, Manchester</div>
<div class="fact"><b>Colours</b>Red, white and black</div>
<div class="fact"><b>League titles</b>20 English top-flight titles</div>
</div>
<h2>Gallery</h2>
<div class="gallery">
)" + picture("crest.jpg", "The club crest") + picture("old-trafford.jpg", "Old Trafford stadium") +
        picture("trophies.jpg", "Trophy cabinet") + R"(</div>
<p>Welcome! Use the menu above to learn about the club's history, its famous stadium and its honours.</p>
)"));

    // ---------- History ----------
    write(PAGES[1].file, layout(PAGES[1], R"(
<h2>A short history</h2>
<div class="timeline">
<p><b>1878</b> &ndash; Founded as Newton Heath LYR F.C. by railway workers in Manchester.</p>
<p><b>1902</b> &ndash; The club is renamed Manchester United.</p>
<p><b>1958</b> &ndash; The Munich air disaster claims the lives of eight players, the "Busby Babes".</p>
<p><b>1968</b> &ndash; Under Sir Matt Busby, United become the first English club to win the European Cup.</p>
<p><b>1986&ndash;2013</b> &ndash; Sir Alex Ferguson's era brings 13 Premier League titles.</p>
<p><b>1999</b> &ndash; The historic Treble: Premier League, FA Cup and Champions League.</p>
<p><b>2008</b> &ndash; Champions League winners again, beating Chelsea in Moscow.</p>
</div>
<div class="gallery">
)" + picture("busby.jpg", "Sir Matt Busby") + picture("ferguson.jpg", "Sir Alex Ferguson") +
        R"(</div>
)"));

    // ---------- Stadium ----------
    write(PAGES[2].file, layout(PAGES[2], R"(
<h2>Old Trafford &ndash; "The Theatre of Dreams"</h2>
<p>Old Trafford has been United's home since 1910. With a capacity of roughly 74,000 it is one of the largest club stadiums in the United Kingdom. The nickname "Theatre of Dreams" was coined by Sir Bobby Charlton.</p>
<div class="facts">
<div class="fact"><b>Opened</b>1910</div>
<div class="fact"><b>Capacity</b>About 74,000</div>
<div class="fact"><b>Location</b>Sir Matt Busby Way, Stretford</div>
</div>
<div class="gallery">
)" + picture("stadium-outside.jpg", "Outside Old Trafford") + picture("stadium-inside.jpg", "Inside the stadium") +
        picture("statue.jpg", "The United Trinity statue") + R"(</div>
)"));

    // ---------- Honours ----------
    write(PAGES[3].file, layout(PAGES[3], R"(
<h2>Major honours</h2>
<table>
<tr><th>Competition</th><th>Titles</th><th>Notable years</th></tr>
<tr><td>English League (top flight)</td><td>20</td><td>1908, 1965, 1993, 1999, 2013</td></tr>
<tr><td>FA Cup</td><td>13</td><td>1909, 1999, 2016, 2024</td></tr>
<tr><td>League Cup</td><td>6</td><td>1992, 2017, 2023</td></tr>
<tr><td>European Cup / Champions League</td><td>3</td><td>1968, 1999, 2008</td></tr>
<tr><td>UEFA Europa League</td><td>1</td><td>2017</td></tr>
<tr><td>UEFA Cup Winners' Cup</td><td>1</td><td>1991</td></tr>
</table>
<p><small>Counts reflect major honours at the time of writing; please check the latest figures before publishing.</small></p>
<div class="gallery">
)" + picture("champions-league.jpg", "Champions League celebration") + picture("premier-league.jpg", "Premier League trophy") +
        R"(</div>
)"));

    std::cout << "\nDone! Put your pictures in an 'images' folder, then open index.html.\n";
    return 0;
}