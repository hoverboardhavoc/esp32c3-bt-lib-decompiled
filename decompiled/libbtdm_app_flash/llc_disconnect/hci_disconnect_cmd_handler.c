/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> hci_disconnect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_disconnect_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    bVar1 = *(byte *)(iVar6 + 0x45);
    uVar5 = bVar1 & 1;
    if ((bVar1 & 1) == 0) {
      puVar3 = (undefined4 *)r_ke_msg_alloc(0x108,param_1 << 8 | 1,0xc);
      *(undefined1 *)(puVar3 + 1) = 1;
      r_llc_proc_state_set(param_1,0);
      *puVar3 = r_llc_disconnect_proc_err_cb;
      cVar4 = *(char *)(param_2 + 2);
      *(char *)(puVar3 + 2) = cVar4;
      if (cVar4 == '\x13') {
        cVar4 = '\x16';
      }
      *(char *)((int)puVar3 + 9) = cVar4;
      r_ke_msg_send(puVar3);
      *(byte *)(iVar6 + 0x45) = *(byte *)(iVar6 + 0x45) | 1;
    }
    else {
      r_ble_log_internal_x1(0x802f0097,(uint)bVar1 << 0x10 | param_1 << 8 | 0x3a);
      uVar5 = 0x3a;
    }
  }
  else {
    uVar5 = 0;
    if ((_sdk_cfg_priv_opts & 0x40) == 0) {
      r_ble_log_internal_x1(0x802f0096,param_1 << 8 | 0xc);
      uVar5 = 0xc;
    }
  }
  r_llc_cmd_stat_send(param_1,param_3,uVar5);
  return 0;
}

