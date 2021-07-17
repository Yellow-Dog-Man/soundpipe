#include "soundpipe.h"
#include "md5.h"
#include "tap.h"
#include "test.h"

int t_verbity(sp_test *tst, sp_data *sp, const char *hash)
{
    uint32_t n;
    int fail;
    sp_verbity *verb;

    fail = 0;

    /* allocate / initialize modules here */
    sp_verbity_create(&verb);
    sp_verbity_init(sp, verb);

    for (n = 0; n < tst->size; n++) {
        SPFLOAT outL, outR;
        SPFLOAT tick;

        tick = n == 0 ? 1.0 : 0.0;

        outL = outR = 0;

        sp_verbity_compute(sp, verb, &tick, &tick,
                           &outL, &outR);

        sp_test_add_sample(tst, (outL + outR) * 0.5);
    }

    fail = sp_test_verify(tst, hash);

    /* destroy functions here */
    sp_verbity_destroy(&verb);

    if (fail) return SP_NOT_OK;
    else return SP_OK;
}
