/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> h4tl.o -> r_h4tl_acl_hdr_rx_evt_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_h4tl_acl_hdr_rx_evt_handler(void)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  (**(code **)(_r_modules_funcs_p + 0xec))(0xb,*(code **)(_r_modules_funcs_p + 0xec));
  (**(code **)(_r_modules_funcs_p + 0x7c))
            (&h4tl_env,&h4tl_env,*(code **)(_r_modules_funcs_p + 0x7c));
  if (_DAT_00011024 == 0) {
    (*(code *)_r_ip_funcs_p[1])(_DAT_00011022,0,0,(code *)_r_ip_funcs_p[1]);
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0x78);
  }
  else {
    iVar1 = (*(code *)*_r_ip_funcs_p)((code *)*_r_ip_funcs_p);
    _DAT_00011020 = (undefined2)iVar1;
    if (iVar1 == 0) {
      _r_hli_funcs_p = 0;
    }
    else {
      _r_hli_funcs_p = (**(code **)(_r_plf_funcs_p + 0xbc))(*(code **)(_r_plf_funcs_p + 0xbc));
      if (_r_hli_funcs_p != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001071a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(_r_modules_funcs_p + 0x74))(&h4tl_env,_DAT_00011024);
        return;
      }
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 100);
  }
                    /* WARNING: Could not recover jumptable at 0x000106e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&h4tl_env);
  return;
}

