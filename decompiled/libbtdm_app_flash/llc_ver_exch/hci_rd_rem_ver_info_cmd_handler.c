/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_ver_exch.o -> hci_rd_rem_ver_info_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_rd_rem_ver_info_cmd_handler(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = r_sdk_config_get_opts();
  uVar3 = 0xc;
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    iVar1 = *(int *)(&llc_env + param_1 * 4);
    uVar3 = 0xc;
    if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
      uVar3 = 0x3a;
      if ((*(byte *)(iVar4 + 0x45) & 2) == 0) {
        puVar2 = (undefined4 *)r_ke_msg_alloc(0x106,param_1 << 8 | 1,0xc);
        *(undefined1 *)(puVar2 + 1) = 2;
        r_llc_proc_state_set(param_1,0);
        *puVar2 = r_llc_ver_proc_err_cb;
        *(undefined1 *)(puVar2 + 2) = 1;
        r_ke_msg_send(puVar2);
        uVar3 = 0;
        *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) | 2;
      }
    }
  }
  r_llc_cmd_stat_send(param_1,param_2,uVar3);
  return 0;
}

