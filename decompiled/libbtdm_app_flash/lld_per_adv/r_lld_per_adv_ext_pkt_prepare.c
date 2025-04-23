/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_ext_pkt_prepare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_per_adv_ext_pkt_prepare
               (int param_1,int param_2,uint param_3,uint param_4,uint param_5,short *param_6,
               short *param_7)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  void *__dest;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  ushort *in_stack_00000000;
  undefined2 uStack_4c;
  undefined1 auStack_4a [5];
  undefined1 uStack_45;
  undefined1 uStack_44;
  
  iVar9 = param_2 * 0xe;
  iVar10 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar15 = (uint)*(byte *)(iVar10 + 0x52) * 9;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = *(ushort *)(iVar6 + iVar9);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar12 = (param_5 & 0x7f) << 1;
  *(ushort *)(iVar6 + iVar9) = uVar3 & 0x8000;
  uVar16 = uVar12;
  if (param_2 == iVar15) {
    uVar16 = param_5 + 10 & 0xff;
  }
  if (*in_stack_00000000 + uVar16 < 0xff) {
    iVar6 = 0;
    sVar5 = 0;
  }
  else {
    iVar6 = 2;
    if (param_5 == 0) {
      if (uVar16 == 0) {
        uVar16 = 1;
      }
      iVar6 = 1;
    }
    uVar12 = iVar6 + 3;
    uVar16 = uVar16 + 3 & 0xff;
    iVar6 = 1;
    sVar5 = 3;
  }
  if (param_5 != 0) {
    cVar1 = *(char *)(iVar10 + 0x56);
    iVar7 = r_llm_tx_path_comp_get();
    pcVar8 = (char *)r_emi_get_mem_addr_by_offset(*param_6 + sVar5);
    sVar5 = sVar5 + 1;
    *pcVar8 = cVar1 + (char)(iVar7 / 10);
  }
  if (param_2 == iVar15) {
    *(char *)(iVar10 + 0x59) = (char)sVar5;
    uStack_4c = 0x2808;
    memcpy(auStack_4a,(void *)(iVar10 + 0x2f),5);
    uStack_45 = (undefined1)*(undefined2 *)(iVar10 + 0x3a);
    uStack_44 = (undefined1)((ushort)*(undefined2 *)(iVar10 + 0x3a) >> 8);
    __dest = (void *)r_emi_get_mem_addr_by_offset(*param_6 + sVar5);
    sVar5 = sVar5 + 9;
    memcpy(__dest,&uStack_4c,9);
  }
  uVar11 = 0;
  uVar3 = *in_stack_00000000;
  uVar14 = (uint)uVar3;
  uVar13 = uVar3;
  if (uVar14 != 0) {
    uVar11 = -uVar16 - 2 & 0xff;
    if (uVar14 < uVar11) {
      uVar11 = uVar14 & 0xff;
    }
    uVar13 = (ushort)uVar11;
    *in_stack_00000000 = uVar3 - uVar13;
  }
  if ((param_4 & 0xfc) != 0) {
    r_assert_err(0,0x10000,500);
  }
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + 6 + iVar7) =
       (ushort)(param_5 << 0xe) | (ushort)(param_4 << 6) | (ushort)uVar12 | (ushort)(iVar6 << 0xc);
  uVar16 = r_co_ble_pkt_dur_in_us(uVar16 + 1 + uVar11 & 0xff,*(undefined1 *)(iVar10 + 0x55));
  uVar14 = 0;
  if (iVar6 != 0) {
    uVar14 = uVar16 / 0x1e + 0xb;
    uVar16 = uVar14 * 0x1e;
    *(short *)(iVar10 + 0x4a) = (short)uVar14;
  }
  uVar3 = *(ushort *)(_p_lld_env + 0xd4);
  bVar2 = *(byte *)(iVar10 + 0x57);
  if (0x3f < bVar2) {
    r_assert_err(0,0x10000,0x2b0);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + 8 + iVar6) =
       (ushort)(uVar3 < 0x33) << 6 | (ushort)bVar2 | (ushort)((uVar14 & 0xff) << 8);
  bVar2 = *(byte *)(iVar10 + 0x55);
  uVar3 = *(ushort *)(iVar10 + 0x4a) >> 8;
  if ((bVar2 & 0xf8) != 0) {
    r_assert_err(0,0x10000,0x31c);
  }
  if (0x1f < uVar3) {
    r_assert_err(0,0x10000,0x31d);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar7 = iVar9 + 10;
  *(ushort *)(iVar6 + iVar7) = (ushort)bVar2 << 5 | uVar3;
  sVar4 = *param_6;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar9 + 0xc + iVar6) = sVar4;
  *param_6 = sVar5 + *param_6;
  if (0xf < param_3) {
    r_assert_err(0,0x10000,0x126);
  }
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + 2 + iVar6) =
       (ushort)((uVar12 + 1 + uVar11 & 0xff) << 8) | (ushort)param_3 | 0x20;
  sVar5 = *param_7;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar9 + 4 + iVar6) = sVar5;
  *param_7 = uVar13 + *param_7;
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = *(ushort *)(iVar6 + iVar9);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar9 + iVar6) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
  if (param_2 == iVar15) {
    *(char *)(iVar10 + 0x5a) = (char)uVar12;
    *(char *)(iVar10 + 0x5b) = (char)uVar11;
  }
  iVar6 = r_bt_rf_coex_st_param_get(4);
  if (iVar6 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [PER ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar6 + 4),
                 *(undefined1 *)(iVar6 + 5));
    }
    bVar2 = *(byte *)(iVar6 + 5);
    if ((bVar2 & 0xf0) != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar9 + iVar7);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar9 + iVar7) = uVar3 & 0xf0ff | (ushort)bVar2 << 8;
    bVar2 = *(byte *)(iVar6 + 4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar6 + iVar7);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + iVar7) = uVar3 & 0xefff | (ushort)bVar2 << 0xc;
  }
  return uVar16;
}

