/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> ble_util_buf.o -> r_ble_util_buf_acl_tx_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 r_ble_util_buf_acl_tx_alloc(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (0x100 < param_1) {
    return 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar1 = (**(code **)(_r_modules_funcs_p + 0x40))
                    (_p_ble_util_buf_env + 0x10,*(code **)(_r_modules_funcs_p + 0x40));
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (iVar1 != 0) {
    uVar3 = *(ushort *)(iVar1 + 4) - 0x9c00 >> 10 & 0xff;
    if (0xb < uVar3) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (uVar3,"ble_util_buf.c",0x171,*(code **)(_r_plf_funcs_p + 0xc));
    }
    if ((uVar3 < *(byte *)(_p_ble_util_buf_env + 0x1bb)) ||
       (iVar2 = (**(code **)(_r_plf_funcs_p + 0x9c))
                          (*(undefined2 *)(iVar1 + 4),param_1,*(code **)(_r_plf_funcs_p + 0x9c)),
       iVar2 == 0)) {
      return *(undefined2 *)(iVar1 + 4);
    }
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    (**(code **)(_r_modules_funcs_p + 0x44))
              (_p_ble_util_buf_env + 0x10,iVar1,*(code **)(_r_modules_funcs_p + 0x44));
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  }
  return 0;
}

