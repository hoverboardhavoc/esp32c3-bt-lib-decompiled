/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_evt_start_cbk(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  ushort uVar13;
  uint uVar14;
  byte bStack_51;
  code *pcStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_34;
  
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0x87);
    uVar11 = (uint)bVar1;
    iVar5 = uVar11 * 0x5a;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar13 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_sdk_config_get_opts_ext();
    uVar13 = uVar13 & 0x1f;
    if ((*(uint *)(iVar6 + 0x28) & 4) != 0) {
      iVar6 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar6 + 0x2c) < 3) {
        r_ble_log_internal_x2
                  (0x40400008,*(undefined1 *)(param_1 + 0x87),*(undefined4 *)(param_1 + 4));
      }
    }
    uVar12 = 0;
    if (((*(ushort *)(param_1 + 0x74) & 0x13) == 0) && (*(int *)(param_1 + 0x68) != 0)) {
      if (*(char *)(param_1 + 0x94) == '\0') {
        uVar12 = 0;
        if (*(char *)(param_1 + 0x95) == '\0') {
          iVar6 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar6 + 0x18) == '\0') {
            r_assert_err(0,0x10000,0x8c0);
          }
          uVar12 = 1;
          r_lld_adv_sync_info_set(*(undefined1 *)(param_1 + 0x87));
        }
      }
      else {
        uVar12 = 0;
      }
    }
    iVar6 = *(int *)(param_1 + 0x58);
    if (iVar6 != -1) {
      iVar8 = *(int *)(param_1 + 4);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar5 + 0x20 + iVar7) = (short)((uint)((iVar6 - iVar8) * 0x8000) >> 0x10);
    }
    uVar14 = (uint)*(byte *)(param_1 + 0x95);
    uVar10 = 0;
    if (uVar14 != 0) {
      bVar2 = *(byte *)(param_1 + 0x87);
      uVar9 = ((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 4) & 0xfffffffU) * 0x271 >> 1) +
              (uint)*(ushort *)(param_1 + 0x7a) * 0x1e;
      if (uVar9 < 0x257ed5) {
        if (uVar9 < 0x3bfc4) {
          uVar14 = 0;
          uVar10 = uVar9 % 0x1e;
          uVar9 = uVar9 / 0x1e & 0xffff;
        }
        else {
          uVar10 = uVar9 % 300;
          uVar9 = uVar9 / 300 & 0xffff;
        }
      }
      else {
        uVar14 = 0;
        uVar9 = 0;
      }
      bVar3 = *(byte *)(param_1 + 0x91);
      uVar4 = *(ushort *)(_p_lld_env + 0xd4);
      if (0x3f < bVar3) {
        r_assert_err(0,0x10000,0x2b0);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar7 = ((uint)bVar2 * 9 & 0xff) * 0xe;
      *(ushort *)(iVar7 + 8 + iVar6) =
           (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar3 | (ushort)(uVar9 << 8) |
           (ushort)(uVar14 << 7);
      bVar2 = *(byte *)(param_1 + 0x90);
      if ((bVar2 & 0xf8) != 0) {
        r_assert_err(0,0x10000,0x31c);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + 10 + iVar6) = (ushort)(uVar9 >> 8) | (ushort)bVar2 << 5;
    }
    r_lld_adv_set_tx_power(uVar11,uVar13);
    r_lld_adv_dynamic_pti_process(param_1,0,uVar12);
    r_bt_rma_get_ant_by_act(uVar13,uVar11,&bStack_51,&pcStack_50);
    if ((bStack_51 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar13 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar5) = uVar13 & 0xff7f | (ushort)bStack_51 << 7;
    if (((uint)pcStack_50 & 0xfe) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar13 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar6) = uVar13 & 0xffbf | (ushort)(byte)pcStack_50 << 6;
    uStack_3c = *(undefined1 *)(param_1 + 0x16);
    pcStack_50 = r_lld_adv_frm_cbk;
    uStack_4c = *(undefined4 *)(param_1 + 4);
    uStack_44 = *(undefined4 *)(param_1 + 0x10);
    uStack_3a = rwip_priority;
    iStack_48 = uVar10 << 1;
    uStack_39 = 0xf;
    uStack_3b = 0;
    uStack_36 = 0;
    uStack_34 = 0;
    uStack_37 = 0;
    uStack_40 = uVar11;
    bStack_38 = bVar1;
    r_sch_prog_push(&pcStack_50);
    *(undefined1 *)(param_1 + 0x89) = 1;
    return;
  }
  r_assert_err(0x10000,0x907);
  return;
}

