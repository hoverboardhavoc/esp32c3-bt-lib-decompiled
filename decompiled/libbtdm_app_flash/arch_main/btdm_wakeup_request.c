/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_wakeup_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void btdm_wakeup_request(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = btdm_get_power_state_impl();
  if (((iVar2 - 1U & 0xff) < 2) && ((int)(_DAT_60042000 << 0x10) < 0)) {
    iVar1 = _DAT_60042004 - _DAT_60042008;
    uVar3 = (**(code **)(_r_osi_funcs_p + 0x8c))(iVar1,0,*(code **)(_r_osi_funcs_p + 0x8c));
    if (200 < uVar3) {
      _DAT_60042000 = _DAT_60042000 | 0x10;
      iVar4 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar4 + 0x28) & 0x200) != 0) {
        iVar4 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar4 + 0x2c) < 3) {
          r_ble_log_internal_x2(0x400c0006,iVar2,iVar1);
        }
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0001026c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

