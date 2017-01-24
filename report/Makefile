default: compile

compile: report.tex
	pdflatex --shell-escape report.tex
	pdflatex --shell-escape report.tex
	pdflatex --shell-escape report.tex
	#mv report.pdf memoco_report.pdf

open:
	open report.pdf

clean:
	rm -vf *.aux *.log *.lof *.lot *.toc *.pdf *.mp *.mps *.dvi *.out *.bbl *.blg
