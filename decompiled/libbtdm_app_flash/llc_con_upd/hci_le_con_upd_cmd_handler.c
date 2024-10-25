/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  byte bVar9;
  ushort uVar10;
  int iVar11;
  int iVar12;
  
  iVar12 = param_1 * 4;
  iVar11 = *(int *)(&llc_env + iVar12);
  if (iVar11 != 0) {
    if ((*(ushort *)(param_2 + 2) < 0xb) &&
       (((uVar4 = r_lld_con_count_get(), 1 < uVar4 || (*(char *)(iVar11 + 0x1c) == '\x03')) ||
        (*(char *)(iVar11 + 0x1d) == '\x03')))) {
      uVar7 = 0x12;
      goto _L246;
    }
  }
  iVar5 = r_sdk_config_get_opts();
  uVar7 = 0xc;
  if (param_1 < *(byte *)(iVar5 + 0xd)) {
    iVar5 = *(int *)(&llc_env + iVar12);
    uVar7 = 0xc;
    if (((iVar5 != 0) && ((*(byte *)(iVar5 + 0x44) & 3) != 3)) &&
       (((iVar5 = r_sdk_config_get_opts(0xc), param_1 < *(byte *)(iVar5 + 0xd) &&
         ((iVar5 = *(int *)(&llc_env + iVar12), iVar5 != 0 &&
          (((int)(uint)*(byte *)(iVar5 + 0x30) >> 1 & 1U) != 0)))) ||
        (uVar7 = 0x1a, (*(ushort *)(iVar11 + 0x42) & 1) != 0)))) {
      uVar7 = 0x3a;
      if ((*(byte *)(iVar11 + 0x45) & 0x10) == 0) {
        iVar5 = r_llc_con_upd_param_in_range
                          (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                           *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8));
        uVar7 = 0x12;
        if (iVar5 != 0) {
          puVar6 = (undefined4 *)r_ke_msg_alloc(0x10b,param_1 << 8 | 1,0x30);
          *(undefined1 *)(puVar6 + 1) = 5;
          r_llc_proc_state_set(param_1,0);
          uVar1 = *(ushort *)(param_2 + 4);
          *puVar6 = r_llc_loc_con_upd_proc_err_cb;
          uVar8 = (uint)uVar1 << 1;
          uVar4 = (uint)*(ushort *)(param_2 + 0xc);
          if (uVar8 < *(ushort *)(param_2 + 0xc)) {
            uVar4 = uVar8;
          }
          uVar2 = *(ushort *)(param_2 + 2);
          *(short *)((int)puVar6 + 0x12) = (short)uVar4;
          uVar10 = *(ushort *)(param_2 + 10);
          uVar4 = (uint)uVar2 << 1;
          if (uVar4 < uVar10) {
            uVar10 = (ushort)uVar4;
          }
          *(ushort *)(puVar6 + 4) = uVar10;
          uVar3 = *(undefined2 *)(param_2 + 6);
          *(ushort *)(puVar6 + 2) = uVar2;
          *(ushort *)((int)puVar6 + 10) = uVar1;
          *(undefined2 *)(puVar6 + 3) = uVar3;
          *(undefined2 *)((int)puVar6 + 0xe) = *(undefined2 *)(param_2 + 8);
          iVar5 = r_sdk_config_get_opts();
          bVar9 = 0;
          if ((param_1 < *(byte *)(iVar5 + 0xd)) && (*(int *)(&llc_env + iVar12) != 0)) {
            bVar9 = (byte)((int)(uint)*(byte *)(*(int *)(&llc_env + iVar12) + 0x30) >> 1) & 1;
          }
          *(byte *)(puVar6 + 0xb) = bVar9 ^ 1;
          *(undefined1 *)((int)puVar6 + 0x2d) = 1;
          *(undefined1 *)((int)puVar6 + 0x2e) = 1;
          r_ke_msg_send(puVar6);
          uVar7 = 0;
          *(byte *)(iVar11 + 0x45) = *(byte *)(iVar11 + 0x45) | 0x10;
        }
      }
    }
  }
_L246:
  r_llc_cmd_stat_send(param_1,param_3,uVar7);
  return 0;
}

