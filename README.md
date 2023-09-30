# mol-emu

An emulator for the MOL-940 metaprogramming language developed in the 1960s by J. Rulifson and D. Engelbart, inventor of the computer mouse.

# Goals (in chronological order)

1. Be able to emulate a small sample program from page 32 of [this PDF](https://bitsavers.org/pdf/sri/arc/rulifson/MOL940_Preliminary_Specification_For_An_Algol-Like_Machine_Oriented_Language_For_The_SDS_940_Mar68.pdf).
2. Be able to emulate the core code (a.k.a. UTILTY (utility) "overlay") of D. Engelbart's oN-Line System (NLS), using the NLS's [(partial) late 1969 source code](https://bitsavers.org/pdf/sri/arc/sds-940/NLS_Sources_Part_1_Nov69.pdf), courtesy of bitsavers.org.
3. Be able to emulate the full NLS system as of late 1969, reconstructed from the aforementioned partial late 1969 source code, as well as using the following for a complete reconstruction:
   * Other (partial) 1966-1969 source code & technical reports provided by J. Rulifson to the Computer History Museum, accessible online [here](https://www.computerhistory.org/collections/catalog/102734175).
   * Other (complete) 1972-1978 source code provided by E. Feinler to the Computer History Museum, accessible online [here](https://www.computerhistory.org/collections/catalog/102706982).
   * Various other NLS documentation (system manuals, technical reports, etc.) courtesy of bitsavers.org, accessible online [here](https://bitsavers.org/pdf/sri/arc/sds-940/) and [here](https://bitsavers.org/pdf/sri/arc/).
