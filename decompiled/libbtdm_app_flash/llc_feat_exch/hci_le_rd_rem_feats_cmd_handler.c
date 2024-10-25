/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> hci_le_rd_rem_feats_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_rd_rem_feats_cmd_handler(uint param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = (int *)(&llc_env + param_1 * 4);
  iVar5 = *piVar1;
  iVar2 = r_sdk_config_get_opts();
  uVar4 = 0xc;
  if (param_1 < *(byte *)(iVar2 + 0xd)) {
    uVar4 = 0xc;
    if ((*piVar1 != 0) && ((*(byte *)(*piVar1 + 0x44) & 3) != 3)) {
      uVar4 = 0x3a;
      if ((*(byte *)(iVar5 + 0x45) & 4) == 0) {
        iVar2 = r_sdk_config_get_opts(0x3a);
        if (((*(byte *)(iVar2 + 0xd) <= param_1) || (*piVar1 == 0)) ||
           (((int)(uint)*(byte *)(*piVar1 + 0x30) >> 3 & 1U) == 0)) {
          uVar4 = 0x1a;
          if ((*(ushort *)(iVar5 + 0x42) & 0x81) == 0) goto _L54;
        }
        puVar3 = (undefined4 *)r_ke_msg_alloc(0x107,param_1 << 8 | 1,0xc);
        *(undefined1 *)(puVar3 + 1) = 4;
        r_llc_proc_state_set(param_1,0);
        *(undefined1 *)(puVar3 + 2) = 1;
        *puVar3 = r_llc_feats_exch_proc_err_cb;
        r_ke_msg_send(puVar3);
        uVar4 = 0;
        *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) | 4;
      }
    }
  }
_L54:
  r_llc_cmd_stat_send(param_1,param_2,uVar4);
  return 0;
}

