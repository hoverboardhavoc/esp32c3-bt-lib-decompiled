/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = btdm_get_power_state_impl();
  if (((iVar2 - 1U & 0xff) < 2) && ((_DAT_60042000 >> 0xf & 1) != 0)) {
    iVar1 = _DAT_60042004 - _DAT_60042008;
    uVar3 = (**(code **)(_r_osi_funcs_p + 0x8c))(iVar1,0,*(code **)(_r_osi_funcs_p + 0x8c));
    if (200 < uVar3) {
      _DAT_60042000 = _DAT_60042000 | 0x10;
      r_ble_log_internal_x3(0x400b01b8,iVar1,_DAT_60042000,iVar2);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010292. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

