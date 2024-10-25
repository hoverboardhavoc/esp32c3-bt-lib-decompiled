/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> hci_disconnect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_disconnect_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_1 * 4), iVar1 != 0))
     && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    uVar3 = 0x3a;
    if ((*(byte *)(iVar5 + 0x45) & 1) == 0) {
      puVar2 = (undefined4 *)r_ke_msg_alloc(0x108,param_1 << 8 | 1,0xc);
      *(undefined1 *)(puVar2 + 1) = 1;
      r_llc_proc_state_set(param_1,0);
      *puVar2 = r_llc_disconnect_proc_err_cb;
      cVar4 = *(char *)(param_2 + 2);
      *(char *)(puVar2 + 2) = cVar4;
      if (cVar4 == '\x13') {
        cVar4 = '\x16';
      }
      *(char *)((int)puVar2 + 9) = cVar4;
      r_ke_msg_send(puVar2);
      uVar3 = 0;
      *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 1;
    }
  }
  else {
    uVar3 = 0;
    if ((_sdk_cfg_priv_opts & 0x40) == 0) {
      uVar3 = 0xc;
    }
  }
  r_llc_cmd_stat_send(param_1,param_3,uVar3);
  return 0;
}

