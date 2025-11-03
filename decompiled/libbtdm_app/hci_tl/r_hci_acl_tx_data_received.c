/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_acl_tx_data_received
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_acl_tx_data_received(uint param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  
  if (DAT_0001201f != '\0') {
    DAT_0001201f = 0;
    return;
  }
  pbVar2 = (byte *)(**(code **)(_r_plf_funcs_p + 0x20))(*(code **)(_r_plf_funcs_p + 0x20));
  if ((param_1 & 0xfff) < (uint)*pbVar2) {
    puVar3 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1106,(param_1 & 0xff) << 8 | 1,0,0xc,*(code **)(_r_modules_funcs_p + 200))
    ;
    *puVar3 = (short)param_1;
    puVar3[1] = (short)param_2;
    iVar1 = _r_modules_funcs_p;
    if (param_2 == 0) {
      param_3 = 0;
    }
    puVar3[2] = param_3;
                    /* WARNING: Could not recover jumptable at 0x000111a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0xe0))(*(code **)(iVar1 + 0xe0));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000111cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))
            (param_2,param_1,"hci_tl.c",0x777,*(code **)(_r_plf_funcs_p + 0xc));
  return;
}

