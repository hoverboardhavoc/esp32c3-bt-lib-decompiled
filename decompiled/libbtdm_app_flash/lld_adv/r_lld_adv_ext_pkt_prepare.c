/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_pkt_prepare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_adv_ext_pkt_prepare
               (int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6,
               int param_7,int param_8)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  ushort *puVar6;
  uint uVar7;
  int iVar8;
  void *pvVar9;
  undefined1 *puVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  byte bStack00000000;
  byte in_stack_00000004;
  byte bStack00000008;
  short *in_stack_0000000c;
  ushort *in_stack_00000010;
  int aiStack_54 [2];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  
  puVar6 = _bStack00000008;
  iVar17 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar16 = param_2 * 0xe;
  uVar4 = *(ushort *)(iVar8 + iVar16);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar13 = -(uint)(param_5 != 0) & 6;
  iVar15 = (-param_6 & 6U) + uVar13;
  *(ushort *)(iVar8 + iVar16) = uVar4 & 0x8000;
  uVar7 = param_7 * 2 + iVar15 & 0xff;
  uVar19 = (-(_bStack00000000 & 0xff) & 0x12) + (-param_8 & 3U) + uVar7 & 0xff;
  if (in_stack_00000004 == 0) {
    if (uVar19 == 0) goto _L484;
  }
  else {
    uVar19 = uVar19 + 1 & 0xff;
  }
  uVar19 = uVar19 + 1 & 0xff;
_L484:
  if ((0xfe < *in_stack_00000010 + uVar19) && (param_8 == 0)) {
    if (uVar19 == 0) {
      uVar19 = 1;
    }
    uVar19 = uVar19 + 3 & 0xff;
    param_8 = 1;
  }
  if (param_6 != 0) {
    pvVar9 = (void *)r_emi_get_mem_addr_by_offset(uVar13 + *_bStack00000008 & 0xffff);
    memcpy(pvVar9,(void *)(iVar17 + 0x2c),6);
  }
  if (param_7 != 0) {
    puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(iVar15 + (uint)*_bStack00000008 & 0xffff);
    *puVar10 = *(undefined1 *)(iVar17 + 0x76);
    puVar10[1] = *(undefined1 *)(iVar17 + 0x77);
  }
  uVar7 = uVar7 + (-param_8 & 3U) & 0xff;
  if ((_bStack00000000 & 0xff) != 0) {
    uVar5 = *(undefined2 *)(_p_lld_env + 0xd6);
    aiStack_54[0] = *(int *)(iVar17 + 0x68) << 0x10;
    aiStack_54[1] = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = uStack_44 & 0xffff0000;
    r_lld_per_adv_init_info_get
              (*(undefined1 *)(iVar17 + 0x88),(int)&uStack_4c + 1,(int)&uStack_48 + 1,aiStack_54 + 1
              );
    uStack_4c = CONCAT31(uStack_4c._1_3_,(byte)uStack_4c & 0x1f | (char)uVar5 << 5);
    pvVar9 = (void *)r_emi_get_mem_addr_by_offset(*_bStack00000008 + uVar7 & 0xffff);
    memcpy(pvVar9,aiStack_54,0x12);
    uVar7 = uVar7 + 0x12 & 0xff;
  }
  if (in_stack_00000004 != 0) {
    cVar2 = *(char *)(iVar17 + 0x8d);
    iVar8 = r_llm_tx_path_comp_get();
    pcVar11 = (char *)r_emi_get_mem_addr_by_offset(*_bStack00000008 + uVar7 & 0xffff);
    *pcVar11 = cVar2 + (char)(iVar8 / 10);
    uVar7 = uVar7 + 1 & 0xff;
  }
  uVar13 = (uint)*in_stack_00000010;
  uVar18 = 0;
  if (uVar13 != 0) {
    uVar18 = -uVar19 - 2 & 0xff;
    if (uVar13 < uVar18) {
      uVar18 = uVar13 & 0xff;
    }
    *in_stack_00000010 = *in_stack_00000010 - (short)uVar18;
  }
  if ((param_4 & 0xfc) != 0) {
    r_assert_err(0,0x10000,500);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar16 + 6 + iVar8) =
       (ushort)in_stack_00000004 << 0xe | (ushort)(param_4 << 6) | (ushort)bStack00000000 << 0xd |
       (ushort)(param_7 << 0xb) | (ushort)(param_6 << 9) | (ushort)(param_5 << 8) | (ushort)uVar19 |
       (ushort)(param_8 << 0xc);
  iVar15 = *(int *)(&lld_adv_env + param_1 * 4);
  in_stack_00000004 = (byte)uVar18;
  iVar8 = (uint)*(byte *)(iVar15 + 0x87) * 9;
  uVar19 = uVar19 + uVar18 + 1 & 0xff;
  uStack_4c = param_5;
  if (param_2 == iVar8) {
    bVar1 = *(byte *)(iVar15 + 0x93);
    iVar16 = r_co_ble_pkt_dur_in_us(uVar19,*(undefined1 *)(iVar15 + 0x8e));
    uVar13 = (iVar16 + 0x96) * (uint)bVar1;
  }
  else {
    uVar13 = r_co_ble_pkt_dur_in_us(uVar19,*(undefined1 *)(iVar15 + 0x90));
    if (param_2 == (uint)*(byte *)(iVar15 + 0x87) * 9 + 1) {
      *(uint *)(iVar15 + 0x70) = uVar13;
    }
  }
  uVar18 = 0;
  if (param_8 != 0) {
    if (DAT_00016470 == 0) {
      iVar16 = 300;
    }
    else {
      iVar16 = DAT_00016470 + -0x96;
    }
    uVar13 = uVar13 + iVar16;
    if (uVar13 < 0x257ed5) {
      if (uVar13 < 0x3bfc4) {
        uVar18 = 0x1e;
      }
      else {
        uVar18 = 300;
      }
      uVar18 = uVar13 / uVar18 + 1;
      if (param_2 == iVar8) {
        *(short *)(iVar15 + 0x7a) = (short)uVar18;
      }
      else {
        *(short *)(iVar15 + 0x7c) = (short)uVar18;
      }
      if (uVar13 < 0x3bfc4) {
        uVar13 = uVar18 * 0x1e;
        param_8 = 0;
      }
      else {
        uVar13 = uVar18 * 300;
      }
    }
    else {
      param_8 = 0;
      uVar18 = 0;
    }
  }
  uVar4 = *(ushort *)(_p_lld_env + 0xd4);
  uVar12 = (uint)*(byte *)(iVar15 + 0x91);
  uVar14 = uVar18 & 0xff;
  if (0x3f < uVar12) {
    uStack_48 = uVar18 & 0xff;
    uStack_44 = uVar12;
    r_assert_err(0,0x10000,0x2b0);
    uVar12 = uStack_44;
    uVar14 = uStack_48;
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  param_2 = param_2 * 0xe;
  *(ushort *)(param_2 + 8 + iVar8) =
       (ushort)(uVar4 < 0x33) << 6 | (ushort)uVar12 | (ushort)(param_8 << 7) | (ushort)(uVar14 << 8)
  ;
  bVar1 = *(byte *)(iVar15 + 0x90);
  if ((bVar1 & 0xf8) != 0) {
    r_assert_err(0,0x10000,0x31c);
  }
  if (uVar18 >> 8 == 0x20) {
    r_assert_err(0,0x10000,0x31d);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar16 = param_2 + 10;
  *(ushort *)(iVar8 + iVar16) = (ushort)bVar1 << 5 | (ushort)(uVar18 >> 8);
  uVar4 = *_bStack00000008;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(param_2 + 0xc + iVar8) = uVar4;
  uVar4 = *_bStack00000008;
  bStack00000008 = (byte)uVar7;
  *puVar6 = bStack00000008 + uVar4;
  uVar7 = 0;
  if (param_6 != 0) {
    uVar7 = *(byte *)(iVar15 + 0x8c) & 1;
  }
  uVar18 = 0;
  if (uStack_4c != 0) {
    uVar18 = *(byte *)(iVar15 + 0x8b) & 1;
  }
  if (0xf < param_3) {
    r_assert_err(0,0x10000,0x126);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar8 + param_2 + 2) =
       (ushort)(uVar18 << 6) | (ushort)param_3 | (ushort)(uVar19 << 8) | (ushort)(uVar7 << 7) | 0x20
  ;
  sVar3 = *in_stack_0000000c;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(param_2 + 4 + iVar8) = sVar3;
  *in_stack_0000000c = (ushort)in_stack_00000004 + *in_stack_0000000c;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar4 = *(ushort *)(iVar8 + param_2);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(param_2 + iVar8) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
  iVar8 = r_bt_rf_coex_st_param_get(4);
  if (iVar8 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [EXT ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar8 + 4),
                 *(undefined1 *)(iVar8 + 5));
    }
    bVar1 = *(byte *)(iVar8 + 5);
    if ((bVar1 & 0xf0) != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar15 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar15 + iVar16);
    iVar15 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar15 + iVar16) = uVar4 & 0xf0ff | (ushort)bVar1 << 8;
    bVar1 = *(byte *)(iVar8 + 4);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar8 + iVar16);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar8 + iVar16) = uVar4 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return uVar13;
}

