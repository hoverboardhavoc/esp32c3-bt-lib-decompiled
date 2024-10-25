/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_free_all_tx_buf
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_free_all_tx_buf(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  for (iVar1 = 0; iVar2 = r_sdk_config_get_opts(), iVar1 < (int)(uint)*(byte *)(iVar2 + 0xd);
      iVar1 = iVar1 + 1) {
    iVar2 = *(int *)(&lld_con_env + iVar1 * 4);
    if (iVar2 != 0) {
      while (iVar3 = r_co_list_pop_front(iVar2 + 0x28), iVar3 != 0) {
        r_ble_util_buf_acl_tx_free(*(undefined2 *)(iVar3 + 4));
      }
    }
  }
  return;
}

