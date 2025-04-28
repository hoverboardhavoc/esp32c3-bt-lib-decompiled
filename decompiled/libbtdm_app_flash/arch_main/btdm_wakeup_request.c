/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar2;
  int iVar3;
  int iVar4;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = btdm_get_power_state_impl();
  if (((iVar1 - 1U & 0xff) < 2) && ((_DAT_60042000 >> 0xf & 1) != 0)) {
    iVar4 = _DAT_60042004 - _DAT_60042008;
    uVar2 = (**(code **)(_r_osi_funcs_p + 0x8c))(iVar4,0,*(code **)(_r_osi_funcs_p + 0x8c));
    if (200 < uVar2) {
      _DAT_60042000 = _DAT_60042000 | 0x10;
      iVar3 = r_sdk_config_get_opts_ext();
      if ((*(uint *)(iVar3 + 0x28) & 0x200) != 0) {
        iVar3 = r_sdk_config_get_opts_ext();
        if (*(byte *)(iVar3 + 0x2c) < 3) {
          r_ble_log_internal_x2(0x400c0006,iVar1,iVar4);
        }
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

