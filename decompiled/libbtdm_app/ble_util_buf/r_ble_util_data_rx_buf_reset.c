/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_data_rx_buf_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_util_data_rx_buf_reset(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = (uint)*(byte *)(_p_ble_util_buf_env + 0x1ba);
  while (iVar3 = _p_ble_util_buf_env, uVar1 = uVar2 - 1, uVar1 != 0xffffffff) {
    uVar4 = uVar1 * 0x400 + 0x7805;
    *(short *)((uVar2 + 0x17) * 8 + _p_ble_util_buf_env + 4) = (short)(uVar4 * 0x10000 >> 0x10);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xc4))
                      ((uVar4 & 0xffff) - 5,*(ushort *)(iVar3 + 0x1b8) + 0xd,
                       *(code **)(_r_plf_funcs_p + 0xc4));
    uVar2 = uVar1;
    if (iVar3 != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"ble_util_buf.c",0x100,*(code **)(_r_plf_funcs_p + 8));
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00010398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x3c))
            (_p_ble_util_buf_env + 8,_p_ble_util_buf_env + 0xc0,8,
             *(undefined1 *)(_p_ble_util_buf_env + 0x1ba),*(code **)(_r_modules_funcs_p + 0x3c));
  return;
}

