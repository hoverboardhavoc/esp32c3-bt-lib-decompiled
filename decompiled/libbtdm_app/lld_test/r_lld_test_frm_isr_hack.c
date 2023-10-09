/*
 * Last changed at upstream commit 7fb979154bec81163d55aa4e3134425aea0d52ab
 * https://github.com/espressif/esp32c3-bt-lib/commit/7fb979154bec81163d55aa4e3134425aea0d52ab
 * Upstream date: 2023-10-09 11:09:21 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(510fd043)
 * Source: libbtdm_app -> lld_test.o -> r_lld_test_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_frm_isr_hack(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (_lld_test_env == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_test.c",0x93,*(code **)(_r_plf_funcs_p + 8));
  }
  if (*(char *)(_lld_test_env + 0x2a) == '\x02') {
    if (*(char *)(_lld_test_env + 0x26) == '\x01') {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(1,*(code **)(_r_ip_funcs_p + 0x6b8));
      puVar1 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x20a,0,0xff,4,*(code **)(_r_modules_funcs_p + 200));
      *puVar1 = 0;
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(iVar2 + 0x44);
      (**(code **)(_r_modules_funcs_p + 0xe0))(puVar1,*(code **)(_r_modules_funcs_p + 0xe0));
                    /* WARNING: Could not recover jumptable at 0x000100b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 500))(1);
      return;
    }
  }
  r_lld_test_frm_isr(param_1,param_2);
  return;
}

