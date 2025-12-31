/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> hci_le_con_upd_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_con_upd_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  
  iVar13 = param_1 * 4;
  iVar12 = *(int *)(&llc_env + iVar13);
  if (((iVar12 == 0) || (10 < *(ushort *)(param_2 + 2))) ||
     ((uVar4 = r_lld_con_count_get(), uVar4 < 2 &&
      ((*(char *)(iVar12 + 0x1c) != '\x03' && (*(char *)(iVar12 + 0x1d) != '\x03')))))) {
    iVar6 = r_sdk_config_get_opts();
    uVar4 = 0xc;
    if (param_1 < *(byte *)(iVar6 + 0xd)) {
      iVar6 = *(int *)(&llc_env + iVar13);
      if (((iVar6 != 0) && ((*(byte *)(iVar6 + 0x44) & 3) != 3)) &&
         (((iVar6 = r_sdk_config_get_opts(), param_1 < *(byte *)(iVar6 + 0xd) &&
           ((iVar6 = *(int *)(&llc_env + iVar13), iVar6 != 0 &&
            (((int)(uint)*(byte *)(iVar6 + 0x30) >> 1 & 1U) != 0)))) ||
          (uVar4 = 0x1a, (*(ushort *)(iVar12 + 0x42) & 1) != 0)))) {
        uVar4 = *(byte *)(iVar12 + 0x45) & 0x10;
        if ((*(byte *)(iVar12 + 0x45) & 0x10) == 0) {
          iVar6 = r_llc_con_upd_param_in_range
                            (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                             *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8));
          if (iVar6 == 0) {
            uVar4 = 0x12;
          }
          else {
            puVar7 = (undefined4 *)r_ke_msg_alloc(0x10b,param_1 << 8 | 1,0x30);
            *(undefined1 *)(puVar7 + 1) = 5;
            r_llc_proc_state_set(param_1,0);
            uVar1 = *(ushort *)(param_2 + 4);
            *puVar7 = r_llc_loc_con_upd_proc_err_cb;
            uVar9 = (uint)uVar1 << 1;
            uVar8 = (uint)*(ushort *)(param_2 + 0xc);
            if (uVar9 < *(ushort *)(param_2 + 0xc)) {
              uVar8 = uVar9;
            }
            uVar2 = *(ushort *)(param_2 + 2);
            *(short *)((int)puVar7 + 0x12) = (short)uVar8;
            uVar11 = *(ushort *)(param_2 + 10);
            uVar8 = (uint)uVar2 << 1;
            if (uVar8 < uVar11) {
              uVar11 = (ushort)uVar8;
            }
            *(ushort *)(puVar7 + 4) = uVar11;
            uVar3 = *(undefined2 *)(param_2 + 6);
            *(ushort *)(puVar7 + 2) = uVar2;
            *(ushort *)((int)puVar7 + 10) = uVar1;
            *(undefined2 *)(puVar7 + 3) = uVar3;
            *(undefined2 *)((int)puVar7 + 0xe) = *(undefined2 *)(param_2 + 8);
            iVar6 = r_sdk_config_get_opts();
            bVar10 = 0;
            if ((param_1 < *(byte *)(iVar6 + 0xd)) && (*(int *)(&llc_env + iVar13) != 0)) {
              bVar10 = (byte)((int)(uint)*(byte *)(*(int *)(&llc_env + iVar13) + 0x30) >> 1) & 1;
            }
            *(byte *)(puVar7 + 0xb) = bVar10 ^ 1;
            *(undefined1 *)((int)puVar7 + 0x2d) = 1;
            *(undefined1 *)((int)puVar7 + 0x2e) = 1;
            r_ke_msg_send(puVar7);
            *(byte *)(iVar12 + 0x45) = *(byte *)(iVar12 + 0x45) | 0x10;
          }
        }
        else {
          uVar4 = 0x3a;
        }
      }
    }
    r_llc_cmd_stat_send(param_1,param_3,uVar4);
    if (iVar12 == 0) {
      return 0;
    }
    uVar4 = param_1 << 8 | uVar4;
    uVar8 = (uint)*(byte *)(iVar12 + 0x45) | (uint)*(ushort *)(iVar12 + 0x42) << 0x10;
    uVar5 = 0x802f0087;
  }
  else {
    r_llc_cmd_stat_send(param_1,param_3,0x12);
    uVar4 = (uint)*(ushort *)(iVar12 + 0x1c);
    uVar8 = (uint)*(ushort *)(param_2 + 2) | param_1 << 0x18;
    uVar5 = 0x802f0086;
  }
  r_ble_log_internal_x2(uVar5,uVar8,uVar4);
  return 0;
}

