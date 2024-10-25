/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_rd_adv_ch_tx_pw_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rd_adv_ch_tx_pw_cmd_handler(undefined4 param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,2);
  pcVar1 = _memcpy;
  (*_r_assert_err)(4,0xd,_r_assert_err);
  uVar2 = (*pcVar1)(1);
  puVar3[1] = uVar2;
  if (*(char *)(_p_llm_env + 0xd7) == '\x02') {
    *puVar3 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    *puVar3 = 0;
  }
  r_hci_send_2_host(puVar3);
  return 0;
}

