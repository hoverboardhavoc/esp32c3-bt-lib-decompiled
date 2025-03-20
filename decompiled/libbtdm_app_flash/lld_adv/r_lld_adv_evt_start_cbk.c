/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
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
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
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
  
  if (param_1 == 0) {
    r_assert_err("lld_adv.c",0x916);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x87);
    uVar13 = (uint)bVar1;
    iVar5 = uVar13 * 0x5a;
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar14 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_sdk_config_get_opts_ext();
    uVar14 = uVar14 & 0x1f;
    if ((*(uint *)(iVar6 + 0x28) & 4) != 0) {
      iVar6 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar6 + 0x2c) < 3) {
        r_ble_log_internal_x2
                  (0x40400008,*(undefined1 *)(param_1 + 0x87),*(undefined4 *)(param_1 + 4));
      }
    }
    uVar12 = 0;
    if (((*(ushort *)(param_1 + 0x74) & 0x13) == 0) &&
       (uVar12 = *(ushort *)(param_1 + 0x74) & 0x13, *(int *)(param_1 + 0x68) != 0)) {
      if (*(char *)(param_1 + 0x94) == '\0') {
        uVar12 = 0;
        if (*(char *)(param_1 + 0x95) == '\0') {
          iVar6 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar6 + 0x18) == '\0') {
            r_assert_err(0,"lld_adv.c",0x8cf);
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
      iVar10 = *(int *)(param_1 + 4);
      iVar7 = r_emi_get_mem_addr_by_offset(0x400);
      *(short *)(iVar7 + iVar5 + 0x20) = (short)((uint)((iVar6 - iVar10) * 0x8000) >> 0x10);
    }
    uVar11 = 0;
    if (*(char *)(param_1 + 0x95) != '\0') {
      bVar2 = *(byte *)(param_1 + 0x87);
      uVar15 = 0x1e;
      uVar9 = ((*(int *)(param_1 + 0x38) - *(int *)(param_1 + 4) & 0xfffffffU) * 0x271 >> 1) +
              (uint)*(ushort *)(param_1 + 0x7a) * 0x1e;
      if (uVar9 < 0x257ed5) {
        if (0x3bfc3 < uVar9) {
          uVar15 = 300;
        }
        uVar8 = uVar9 < 0x3bfc4 ^ 1;
        uVar11 = 0x1e;
        uVar15 = uVar9 / uVar15 & 0xffff;
        if (0x3bfc3 < uVar9) {
          uVar11 = 300;
        }
        uVar11 = uVar9 % uVar11;
      }
      else {
        uVar8 = 0;
        uVar15 = 0;
      }
      bVar3 = *(byte *)(param_1 + 0x91);
      uVar4 = *(ushort *)(_p_lld_env + 0xd4);
      if ((bVar3 & 0xc0) != 0) {
        r_assert_err(0,"lld_adv.c",0x2b0);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar7 = ((uint)bVar2 * 9 & 0xff) * 0xe;
      *(ushort *)(iVar6 + iVar7 + 8) =
           (ushort)(uVar4 < 0x33) << 6 | (ushort)bVar3 | (ushort)(uVar8 << 7) |
           (ushort)((uVar15 & 0xff) << 8);
      uVar9 = (uint)*(byte *)(param_1 + 0x90) << 5;
      if ((uVar9 & 0xffffff1f) != 0) {
        r_assert_err(0,"lld_adv.c",0x31c);
      }
      iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar7 + 10 + iVar6) = (ushort)uVar9 | (ushort)(uVar15 >> 8);
    }
    r_lld_adv_set_tx_power(uVar13,uVar14);
    r_lld_adv_dynamic_pti_process(param_1,0,uVar12);
    r_bt_rma_get_ant_by_act(uVar14,uVar13,&bStack_61,&pcStack_60);
    if (((uint)bStack_61 << 7 & 0xffffff7f) != 0) {
      r_assert_err(0,"lld_adv.c",0x82);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar14 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar5) = uVar14 & 0xff7f | (ushort)((uint)bStack_61 << 7);
    uVar15 = ((uint)pcStack_60 & 0xff) << 6;
    if ((uVar15 & 0xffffffbf) != 0) {
      r_assert_err(0,"lld_adv.c",0x8e);
    }
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    uVar14 = *(ushort *)(iVar6 + iVar5);
    iVar6 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar6 + iVar5) = uVar14 & 0xffbf | (ushort)uVar15;
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
    uStack_50 = uVar13;
    bStack_48 = bVar1;
    r_sch_prog_push(&pcStack_60);
    *(undefined1 *)(param_1 + 0x89) = 1;
  }
  return;
}

