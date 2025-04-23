/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> vhci.o -> r_vhci_flow_on
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_vhci_flow_on(void)

{
  int iVar1;
  int aiStack_14 [2];
  
  if (_vhci_env_p != 0) {
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00010328. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_osi_funcs_p + 0x38))
                (*(undefined4 *)(_vhci_env_p + 4),*(code **)(_r_osi_funcs_p + 0x38));
      return;
    }
    aiStack_14[0] = 0;
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x30))(aiStack_14,*(code **)(_r_osi_funcs_p + 0x30));
    if ((iVar1 == 1) && (aiStack_14[0] != 0)) {
      (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
    }
  }
  return;
}

