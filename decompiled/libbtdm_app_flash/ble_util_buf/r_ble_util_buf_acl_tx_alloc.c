/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> ble_util_buf.o -> r_ble_util_buf_acl_tx_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 r_ble_util_buf_acl_tx_alloc(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (0x100 < param_1) {
    return 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = r_co_list_pop_front(_p_ble_util_buf_env + 0x10);
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (iVar2 != 0) {
    uVar1 = *(ushort *)(iVar2 + 4) - 0x9c00 >> 10;
    uVar4 = uVar1 & 0xff;
    if (0xb < uVar4) {
      r_assert_param(uVar4,"ble_util_buf.c",0x171);
    }
    if ((uVar4 < *(byte *)(_p_ble_util_buf_env + 0x1bb)) ||
       (iVar3 = r_emi_alloc_em_mapping_by_offset(*(undefined2 *)(iVar2 + 4),param_1), iVar3 == 0)) {
      r_ble_log_internal_x2(0x20e3006b,iVar2,(uint)*(ushort *)(iVar2 + 4) | (uVar1 & 0xff) << 0x10);
      return *(undefined2 *)(iVar2 + 4);
    }
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    r_co_list_push_back(_p_ble_util_buf_env + 0x10,iVar2);
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  }
  return 0;
}

