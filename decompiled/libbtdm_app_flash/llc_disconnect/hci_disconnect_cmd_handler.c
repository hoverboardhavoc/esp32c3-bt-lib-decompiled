/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
    if ((*(byte *)(iVar5 + 0x45) & 1) != 0) goto _L24;
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
    *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 1;
  }
  else {
    uVar3 = 0xc;
    if ((_sdk_cfg_priv_opts & 0x40) == 0) goto _L24;
  }
  uVar3 = 0;
_L24:
  r_llc_cmd_stat_send(param_1,param_3,uVar3);
  return 0;
}

