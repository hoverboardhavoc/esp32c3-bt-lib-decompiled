/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
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
  uint uVar12;
  undefined4 uVar13;
  ushort uVar14;
  uint uVar15;
  byte bStack_61;
  code *pcStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  byte bStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_44;
  
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0x87);
    uVar12 = (uint)bVar1;
    iVar5 = uVar12 * 0x5a;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar13 = 0;
    uVar14 = *(ushort *)(iVar6 + iVar5);
    r_ble_log_internal_x2(0x404000ce,*(undefined4 *)(param_1 + 4),*(undefined1 *)(param_1 + 0x87));
    uVar14 = uVar14 & 0x1f;
    if (((*(ushort *)(param_1 + 0x74) & 0x13) == 0) && (*(int *)(param_1 + 0x68) != 0)) {
      if (*(char *)(param_1 + 0x94) == '\0') {
        uVar13 = 0;
        if (*(char *)(param_1 + 0x95) == '\0') {
          iVar6 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar6 + 0x18) == '\0') {
            r_assert_err(0,0x10000,0x8ff);
          }
          uVar13 = 1;
          r_lld_adv_sync_info_set(*(undefined1 *)(param_1 + 0x87));
        }
      }
      else {
        uVar13 = 0;
      }
    }
    iVar6 = *(int *)(param_1 + 0x58);
    if (iVar6 != -1) {
      iVar8 = *(int *)(param_1 + 4);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar5 + 0x20 + iVar7) = (short)((uint)((iVar6 - iVar8) * 0x8000) >> 0x10);
    }
    uVar11 = 0;
    if (*(char *)(param_1 + 0x95) != '\0') {
      bVar2 = *(byte *)(param_1 + 0x87);
      uVar15 = 0x1e;
      uVar10 = ((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 4) & 0xfffffffU) * 0x271 >> 1) +
               (uint)*(ushort *)(param_1 + 0x7a) * 0x1e;
      if (uVar10 < 0x257ed5) {
        if (0x3bfc3 < uVar10) {
          uVar15 = 300;
        }
        uVar9 = uVar10 < 0x3bfc4 ^ 1;
        uVar11 = 0x1e;
        uVar15 = uVar10 / uVar15 & 0xffff;
        if (0x3bfc3 < uVar10) {
          uVar11 = 300;
        }
        uVar11 = uVar10 % uVar11;
      }
      else {
        uVar9 = 0;
        uVar15 = 0;
      }
      bVar3 = *(byte *)(param_1 + 0x91);
      uVar4 = *(ushort *)(_p_lld_env + 0xd4);
      if ((bVar3 & 0xc0) != 0) {
        r_assert_err(0,0x10000,0x2b0);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar7 = ((uint)bVar2 * 9 & 0xff) * 0xe;
      *(ushort *)(iVar7 + 8 + iVar6) =
           (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar3 | (ushort)(uVar9 << 7) |
           (ushort)((uVar15 & 0xff) << 8);
      uVar10 = (uint)*(byte *)(param_1 + 0x90) << 5;
      if ((uVar10 & 0xffffff1f) != 0) {
        r_assert_err(0,0x10000,0x31c);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + 10 + iVar6) = (ushort)(uVar15 >> 8) | (ushort)uVar10;
    }
    r_lld_adv_set_tx_power(uVar12,uVar14);
    r_lld_adv_dynamic_pti_process(param_1,0,uVar13);
    r_bt_rma_get_ant_by_act(uVar14,uVar12,&bStack_61,&pcStack_60);
    if (((uint)bStack_61 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,0x10000,0x82);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar14 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar5) = uVar14 & 0xff7f | (ushort)((uint)bStack_61 << 7);
    uVar15 = ((uint)pcStack_60 & 0xff) << 6;
    if ((uVar15 & 0xffffffbf) != 0) {
      r_assert_err(0,0x10000,0x8e);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar14 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar5 + iVar6) = uVar14 & 0xffbf | (ushort)uVar15;
    pcStack_60 = r_lld_adv_frm_cbk;
    uStack_5c = *(undefined4 *)(param_1 + 4);
    iStack_58 = uVar11 << 1;
    uStack_54 = *(undefined4 *)(param_1 + 0x10);
    uStack_4c = *(undefined1 *)(param_1 + 0x16);
    uStack_4b = 0;
    uStack_46 = 0;
    uStack_44 = 0;
    uStack_4a = rwip_priority;
    uStack_49 = 0xf;
    uStack_47 = 0;
    uStack_50 = uVar12;
    bStack_48 = bVar1;
    r_sch_prog_push(&pcStack_60);
    *(undefined1 *)(param_1 + 0x89) = 1;
    return;
  }
  r_assert_err(0x10000,0x946);
  return;
}

