/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
                    /* WARNING: Could not recover jumptable at 0x00010336. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_osi_funcs_p + 0x38))
                (*(undefined4 *)(_vhci_env_p + 4),*(code **)(_r_osi_funcs_p + 0x38));
      return;
    }
    aiStack_14[0] = 0;
    iVar1 = (**(code **)(_r_osi_funcs_p + 0x30))
                      (*(undefined4 *)(_vhci_env_p + 4),aiStack_14,*(code **)(_r_osi_funcs_p + 0x30)
                      );
    if ((iVar1 == 1) && (aiStack_14[0] != 0)) {
      (**(code **)(_r_osi_funcs_p + 0x20))(*(code **)(_r_osi_funcs_p + 0x20));
    }
  }
  return;
}

