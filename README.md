**Banking**
This very simple application maintains an array of client swith their bank accounts and supports two functionalities : a method to transfer money from one bank account to another as well as a verify method tocheckthatallaccountsareinaconsistentstate.Asdescribedbelowyouwilldevelopthreeextensionsoftheoriginalprogram.Thefinalversionoftheprogramshouldbecapable of executing all different transfer functions.

1.Writeamultithreadedversionoftheprogram.Addatransfer_multithread()functionthatisexecutedasanewthread.Thenumberofthreadsexecutingtransfer_multithread()needs to be configurable.
2.Writeanewtransfer_atomic()functionthatutilizesatomicstoperformthetransfer.Makesure that the verify function succeeds after running the concurrent transfers.
3.Writeanewtransfer_critical()functionthatperformsanadditionalcheckbeforeexecutingamoneytransfer:Thetransfercanonlybeperformediftheamountinthesourceaccountisatleasttheamountofthetransfer.Usecriticalsectionstoenforcethisconstraint and to guarantee consistency (verify needs to always succeed).
4.Runthecodefrom1.(transfer_multithread())withdifferentthreadcounts.Doestheverify function fail? Explain why.
5.Measurethethroughputofthethreefunctions(1.-3.)andplotthemaspartofyourdocument.Throughputhereisdefinedastransfers/secontheY-axisandnumberofthreads on the X-axis.
6.HighContention:Reducethenumberofbankaccountsto1024,256and64.Reruntheexperimentsfrom5.Howdoesasmallermoneyarrayaffectthroughputandthreadscalability?
