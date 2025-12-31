/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_pkt_prepare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_adv_ext_pkt_prepare
               (int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7
               ,int param_8)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  void *pvVar9;
  undefined1 *puVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  byte in_stack_00000000;
  byte in_stack_00000004;
  byte bStack00000008;
  short *in_stack_0000000c;
  ushort *in_stack_00000010;
  int iStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  
  puVar5 = _bStack00000008;
  iVar17 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar18 = param_2 * 0xe;
  uVar4 = *(ushort *)(iVar8 + iVar18);
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar8 + iVar18) = uVar4 & 0x8000;
  uVar12 = 6;
  if (param_5 == 0) {
    uVar12 = 0;
  }
  uVar14 = uVar12;
  if (param_6 != 0) {
    uVar14 = uVar12 + 6;
  }
  uVar7 = uVar14;
  if (param_7 != 0) {
    uVar7 = uVar14 + 2;
  }
  uVar15 = uVar7;
  if (param_8 != 0) {
    uVar15 = uVar7 + 3;
  }
  if (in_stack_00000000 == 0) {
    if (in_stack_00000004 != 0) goto _L527;
    if (uVar15 == 0) goto _L530;
  }
  else {
    uVar15 = uVar15 + 0x12;
    if (in_stack_00000004 != 0) {
_L527:
      uVar15 = uVar15 + 1;
    }
  }
  uVar15 = uVar15 + 1 & 0xff;
_L530:
  if ((0xfe < *in_stack_00000010 + uVar15) && (param_8 == 0)) {
    if (uVar15 == 0) {
      uVar15 = 1;
    }
    uVar15 = uVar15 + 3 & 0xff;
    param_8 = 1;
  }
  if (param_6 != 0) {
    pvVar9 = (void *)r_emi_get_mem_addr_by_offset(*_bStack00000008 + uVar12 & 0xffff);
    memcpy(pvVar9,(void *)(iVar17 + 0x2c),6);
  }
  if (param_7 != 0) {
    puVar10 = (undefined1 *)r_emi_get_mem_addr_by_offset(*_bStack00000008 + uVar14 & 0xffff);
    *puVar10 = *(undefined1 *)(iVar17 + 0x76);
    puVar10[1] = *(undefined1 *)(iVar17 + 0x77);
  }
  if (param_8 != 0) {
    uVar7 = uVar7 + 3;
  }
  if (in_stack_00000000 != 0) {
    cVar2 = *(char *)(_p_lld_env + 0xd6);
    iStack_54 = *(int *)(iVar17 + 0x68) << 0x10;
    iStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = uStack_44 & 0xffff0000;
    r_lld_per_adv_init_info_get
              (*(undefined1 *)(iVar17 + 0x88),(int)&uStack_4c + 1,(int)&uStack_48 + 1,&iStack_50);
    uStack_4c = CONCAT31(uStack_4c._1_3_,(byte)uStack_4c & 0x1f | cVar2 << 5);
    pvVar9 = (void *)r_emi_get_mem_addr_by_offset(*_bStack00000008 + uVar7 & 0xffff);
    uVar7 = uVar7 + 0x12;
    memcpy(pvVar9,&iStack_54,0x12);
  }
  if (in_stack_00000004 != 0) {
    cVar2 = *(char *)(iVar17 + 0x8d);
    iVar8 = r_llm_tx_path_comp_get();
    pcVar11 = (char *)r_emi_get_mem_addr_by_offset(*_bStack00000008 + uVar7 & 0xffff);
    uVar7 = uVar7 + 1;
    *pcVar11 = cVar2 + (char)(iVar8 / 10);
  }
  uVar12 = (uint)*in_stack_00000010;
  uVar14 = 0;
  if (uVar12 != 0) {
    uVar14 = -uVar15 - 2 & 0xff;
    if (uVar12 < uVar14) {
      uVar14 = uVar12 & 0xff;
    }
    *in_stack_00000010 = *in_stack_00000010 - (short)uVar14;
  }
  if ((param_4 << 6 & 0xffffff3fU) != 0) {
    r_assert_err(0,0x10000,500);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar18 + 6 + iVar8) =
       (ushort)in_stack_00000004 << 0xe | (ushort)(param_4 << 6) | (ushort)in_stack_00000000 << 0xd
       | (ushort)(param_7 << 0xb) | (ushort)(param_6 << 9) | (ushort)(param_5 << 8) | (ushort)uVar15
       | (ushort)(param_8 << 0xc);
  iVar17 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar8 = (uint)*(byte *)(iVar17 + 0x87) * 9;
  uVar12 = uVar15 + uVar14 + 1 & 0xff;
  iStack_50 = param_5;
  if (param_2 == iVar8) {
    bVar1 = *(byte *)(iVar17 + 0x93);
    iVar18 = r_co_ble_pkt_dur_in_us(uVar12,*(undefined1 *)(iVar17 + 0x8e));
    uVar15 = (iVar18 + 0x96) * (uint)bVar1;
  }
  else {
    uVar15 = r_co_ble_pkt_dur_in_us(uVar12,*(undefined1 *)(iVar17 + 0x90));
    if (param_2 == (uint)*(byte *)(iVar17 + 0x87) * 9 + 1) {
      *(uint *)(iVar17 + 0x70) = uVar15;
    }
  }
  uVar6 = 0;
  if (param_8 != 0) {
    if (DAT_000165a4 == 0) {
      iVar18 = 300;
    }
    else {
      iVar18 = DAT_000165a4 + -0x96;
    }
    uVar15 = uVar15 + iVar18;
    if (uVar15 < 0x257ed5) {
      uVar6 = 0x1e;
      if (0x3bfc3 < uVar15) {
        uVar6 = 300;
      }
      uVar6 = uVar15 / uVar6 + 1;
      if (param_2 == iVar8) {
        *(short *)(iVar17 + 0x7a) = (short)uVar6;
      }
      else {
        *(short *)(iVar17 + 0x7c) = (short)uVar6;
      }
      if (uVar15 < 0x3bfc4) {
        uVar15 = uVar6 * 0x1e;
        param_8 = 0;
      }
      else {
        uVar15 = uVar6 * 300;
      }
    }
    else {
      param_8 = 0;
      uVar6 = 0;
    }
  }
  bVar1 = *(byte *)(iVar17 + 0x91);
  uVar4 = *(ushort *)(_p_lld_env + 0xd4);
  uVar16 = uVar6 << 8;
  uVar13 = (uint)bVar1;
  iVar8 = param_8 << 7;
  if ((bVar1 & 0xc0) != 0) {
    uStack_4c = (uint)bVar1;
    uStack_48 = param_8 << 7;
    uStack_44 = uVar6 << 8;
    r_assert_err(0,0x10000,0x2b0);
    uVar16 = uStack_44;
    uVar13 = uStack_4c;
    iVar8 = uStack_48;
  }
  iVar18 = r_emi_get_mem_addr_by_offset(0x1400);
  param_2 = param_2 * 0xe;
  *(ushort *)(param_2 + 8 + iVar18) =
       (ushort)(uVar4 < 0x33) << 6 | (ushort)uVar13 | (ushort)uVar16 | (ushort)iVar8;
  uVar16 = (uint)*(byte *)(iVar17 + 0x90) << 5;
  if ((uVar16 & 0xffffff1f) != 0) {
    r_assert_err(0,0x10000,0x31c);
  }
  if ((uVar6 >> 8 & 0xffffffe0) != 0) {
    r_assert_err(0,0x10000,0x31d);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar18 = param_2 + 10;
  *(ushort *)(iVar8 + iVar18) = (ushort)uVar16 | (ushort)(uVar6 >> 8);
  uVar4 = *_bStack00000008;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(param_2 + 0xc + iVar8) = uVar4;
  uVar4 = *_bStack00000008;
  bStack00000008 = (byte)uVar7;
  *puVar5 = uVar4 + bStack00000008;
  uVar7 = 0;
  if (param_6 != 0) {
    uVar7 = *(byte *)(iVar17 + 0x8c) & 1;
  }
  uVar6 = 0;
  if (iStack_50 != 0) {
    uVar6 = *(byte *)(iVar17 + 0x8b) & 1;
  }
  if ((param_3 & 0xfffffff0) != 0) {
    r_assert_err(0,0x10000,0x126);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar8 + param_2 + 2) =
       (ushort)(uVar6 << 6) | (ushort)param_3 | (ushort)(uVar12 << 8) | (ushort)(uVar7 << 7) | 0x20;
  sVar3 = *in_stack_0000000c;
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(param_2 + 4 + iVar8) = sVar3;
  *in_stack_0000000c = *in_stack_0000000c + (short)uVar14;
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
    uVar12 = (uint)*(byte *)(iVar8 + 5) << 8;
    if ((uVar12 & 0xf000) != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar17 + iVar18);
    iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar17 + iVar18) = uVar4 & 0xf0ff | (ushort)uVar12;
    bVar1 = *(byte *)(iVar8 + 4);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar4 = *(ushort *)(iVar8 + iVar18);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar8 + iVar18) = uVar4 & 0xefff | (ushort)bVar1 << 0xc;
  }
  return uVar15;
}

