#include<iostream>
#include<CDC8600.hh>
#include<ISA.hh>

namespace CDC8600
{
    vector<word> 	MEM(params::MEM::N);
    uint32_t		FreeMEM;
    Processor		PROC;

    word& Processor::X
    (
        uint8_t	i
    )
    {
	cout << "MEM[" << XA*32 + i << "] = " << MEM[XA*32+i].u() << endl;
	return MEM[XA*32 + i];
    }

    void reset
    (
    )
    {
	for (uint32_t i = 0; i < params::MEM::N; i++) MEM[i].u() = 0;
	FreeMEM = 256*32;
	PROC.XA = 0;
    }

    void *memalloc
    (
        u64	N
    )
    {
	cout << "FreeMEM = " << FreeMEM << endl;
	void *addr = &(MEM[FreeMEM]);
	cout << "addr = " << addr << endl;
	FreeMEM += N;
	return addr;
    }

    call0 Call(void (*f)())
    {
	return call0(f);
    }
} // namespace 8600
