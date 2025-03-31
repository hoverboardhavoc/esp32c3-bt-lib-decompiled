/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app -> lld.o -> r_lld_rpa_renew
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (_lld_rpa_renew_env != 0) {
                    /* WARNING: Could not recover jumptable at 0x00011d12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0x10))(0,0,"lld.c",0x55e);
    return;
  }
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x120))(0x30,0,*(code **)(_r_modules_funcs_p + 0x120));
  iVar2 = _r_ip_funcs_p;
  _lld_rpa_renew_env = iVar1;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(_r_ip_funcs_p + 0x298);
    uVar3 = *(undefined4 *)(iVar2 + 0x29c);
    *(undefined1 *)(iVar1 + 0x17) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x18) = uVar3;
    *(undefined1 *)(iVar1 + 0x16) = rwip_priority;
    *(undefined4 *)(iVar1 + 0x10) = 5000;
    pcVar4 = *(code **)(iVar2 + 0x264);
    *(undefined2 *)(iVar1 + 0x14) = 0x60a1;
    uVar3 = (*pcVar4)(pcVar4);
    iVar2 = _r_ip_funcs_p;
    *(undefined4 *)(iVar1 + 4) = uVar3;
    *(undefined4 *)(iVar1 + 8) = 0;
    iVar2 = (**(code **)(iVar2 + 0x6b0))(iVar1,*(code **)(iVar2 + 0x6b0));
    if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00011cec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x558);
      return;
    }
  }
  return;
}

