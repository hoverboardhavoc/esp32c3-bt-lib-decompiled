/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_acl_hdr_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_acl_hdr_rx_evt_handler(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  (**(code **)(_r_modules_funcs_p + 0xec))(0xb,*(code **)(_r_modules_funcs_p + 0xec));
  (**(code **)(_r_modules_funcs_p + 0x7c))
            (&h4tl_env,&h4tl_env,*(code **)(_r_modules_funcs_p + 0x7c));
  if (_DAT_00011028 == 0) {
    (*(code *)_r_ip_funcs_p[1])(_DAT_00011026,0,0,(code *)_r_ip_funcs_p[1]);
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x78);
  }
  else {
    iVar1 = (*(code *)*_r_ip_funcs_p)((code *)*_r_ip_funcs_p);
    _DAT_00011024 = (undefined2)iVar1;
    if (iVar1 == 0) {
      _r_hli_funcs_p = 0;
    }
    else {
      _r_hli_funcs_p = (**(code **)(_r_plf_funcs_p + 0xbc))(*(code **)(_r_plf_funcs_p + 0xbc));
      if (_r_hli_funcs_p != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001071e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_modules_funcs_p + 0x74))
                  (&h4tl_env,_DAT_00011028,*(code **)(_r_modules_funcs_p + 0x74));
        return;
      }
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 100);
  }
                    /* WARNING: Could not recover jumptable at 0x000106f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&h4tl_env,UNRECOVERED_JUMPTABLE);
  return;
}

