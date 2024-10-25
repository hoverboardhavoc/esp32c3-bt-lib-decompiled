/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_set_rslv_priv_addr_to_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_rslv_priv_addr_to_cmd_handler(short *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x12;
  if ((ushort)(*param_1 - 1U) < 0xa1b8) {
    *(short *)(_p_llm_env + 0xc4) = *param_1;
    iVar2 = r_ke_timer_active(6,0);
    uVar1 = 0;
    if (iVar2 != 0) {
      r_ke_timer_clear(6,0);
      r_ke_timer_set(6,0,(uint)*(ushort *)(_p_llm_env + 0xc4) * 100);
    }
  }
  r_llm_cmd_cmp_send(param_2,uVar1);
  return 0;
}

