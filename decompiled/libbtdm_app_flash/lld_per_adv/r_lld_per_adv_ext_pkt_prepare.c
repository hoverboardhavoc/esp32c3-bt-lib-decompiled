/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_ext_pkt_prepare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_lld_per_adv_ext_pkt_prepare
              (int param_1,int param_2,uint param_3,int param_4,int param_5,short *param_6,
              short *param_7)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  void *__dest;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  ushort *in_stack_00000000;
  undefined2 uStack_4c;
  undefined1 auStack_4a [5];
  undefined1 uStack_45;
  undefined1 uStack_44;
  
  iVar6 = param_2 * 0xe;
  iVar12 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar15 = (uint)*(byte *)(iVar12 + 0x52) * 9;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = *(ushort *)(iVar7 + iVar6);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar6) = uVar3 & 0x8000;
  if (param_5 == 0) {
    iVar11 = 0;
    iVar7 = 0;
    if (param_2 != iVar15) goto _L128;
    iVar7 = 1;
  }
  else {
    iVar11 = 2;
    iVar7 = 2;
    if (param_2 != iVar15) goto _L128;
    iVar7 = 2;
  }
  iVar7 = iVar7 + 9;
_L128:
  if ((uint)*in_stack_00000000 + iVar7 < 0xff) {
    iVar14 = 0;
    sVar5 = 0;
  }
  else {
    if ((iVar11 == 0) && (iVar11 = 1, iVar7 == 0)) {
      iVar7 = 1;
    }
    iVar11 = iVar11 + 3;
    iVar7 = iVar7 + 3;
    iVar14 = 1;
    sVar5 = 3;
  }
  if (param_5 != 0) {
    cVar1 = *(char *)(iVar12 + 0x56);
    iVar8 = r_llm_tx_path_comp_get();
    pcVar9 = (char *)r_emi_get_mem_addr_by_offset(*param_6 + sVar5);
    sVar5 = sVar5 + 1;
    *pcVar9 = cVar1 + (char)(iVar8 / 10);
  }
  if (param_2 == iVar15) {
    *(char *)(iVar12 + 0x59) = (char)sVar5;
    uStack_4c = 0x2808;
    memcpy(auStack_4a,(void *)(iVar12 + 0x2f),5);
    uStack_45 = (undefined1)*(undefined2 *)(iVar12 + 0x3a);
    uStack_44 = (undefined1)((ushort)*(undefined2 *)(iVar12 + 0x3a) >> 8);
    __dest = (void *)r_emi_get_mem_addr_by_offset(*param_6 + sVar5);
    sVar5 = sVar5 + 9;
    memcpy(__dest,&uStack_4c,9);
  }
  uVar13 = 0;
  uVar10 = (uint)*in_stack_00000000;
  if (uVar10 != 0) {
    uVar13 = -iVar7 - 2U & 0xff;
    if (uVar10 < uVar13) {
      uVar13 = uVar10 & 0xff;
    }
    *in_stack_00000000 = *in_stack_00000000 - (short)uVar13;
  }
  if ((param_4 << 6 & 0xffffff3fU) != 0) {
    r_assert_err(0,"lld_per_adv.c",500);
  }
  iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar8 + iVar6 + 6) =
       (ushort)(param_5 << 0xe) | (ushort)(param_4 << 6) | (ushort)iVar11 | (ushort)(iVar14 << 0xc);
  iVar7 = r_co_ble_pkt_dur_in_us(iVar7 + 1 + uVar13 & 0xff,*(undefined1 *)(iVar12 + 0x55));
  iVar8 = 0;
  if (iVar14 != 0) {
    iVar8 = (iVar7 + 300U) / 0x1e + 1;
    iVar7 = iVar8 * 0x1e;
    *(short *)(iVar12 + 0x4a) = (short)iVar8;
  }
  bVar2 = *(byte *)(iVar12 + 0x57);
  uVar3 = *(ushort *)(_p_lld_env + 0xd4);
  if ((bVar2 & 0xc0) != 0) {
    r_assert_err(0,"lld_per_adv.c",0x2b0);
  }
  iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar14 + iVar6 + 8) =
       (ushort)(uVar3 < 0x33) << 6 | (ushort)bVar2 | (ushort)(iVar8 << 8);
  uVar3 = *(ushort *)(iVar12 + 0x4a) >> 8;
  uVar10 = (uint)*(byte *)(iVar12 + 0x55) << 5;
  if ((uVar10 & 0xffffff1f) != 0) {
    r_assert_err(0,"lld_per_adv.c",0x31c);
  }
  if ((uVar3 & 0xffe0) != 0) {
    r_assert_err(0,"lld_per_adv.c",0x31d);
  }
  iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar8 = iVar6 + 10;
  *(ushort *)(iVar14 + iVar8) = (ushort)uVar10 | uVar3;
  sVar4 = *param_6;
  iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar14 + iVar6 + 0xc) = sVar4;
  *param_6 = sVar5 + *param_6;
  if ((param_3 & 0xfffffff0) != 0) {
    r_assert_err(0,"lld_per_adv.c",0x126);
  }
  iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar14 + iVar6 + 2) =
       (ushort)((iVar11 + 1 + uVar13 & 0xff) << 8) | (ushort)param_3 | 0x20;
  sVar5 = *param_7;
  iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar14 + iVar6 + 4) = sVar5;
  *param_7 = *param_7 + (short)uVar13;
  iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = *(ushort *)(iVar14 + iVar6);
  iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar14 + iVar6) = uVar3 & 0x7fff;
  if (param_2 == iVar15) {
    *(char *)(iVar12 + 0x5a) = (char)iVar11;
    *(char *)(iVar12 + 0x5b) = (char)uVar13;
  }
  iVar6 = r_bt_rf_coex_st_param_get(4);
  if (iVar6 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [PER ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar6 + 4),
                 *(undefined1 *)(iVar6 + 5));
    }
    uVar10 = (uint)*(byte *)(iVar6 + 5) << 8;
    if ((uVar10 & 0xf000) != 0) {
      r_assert_err(0,"lld_per_adv.c",0x33f);
    }
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar12 + iVar8);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar12 + iVar8) = uVar3 & 0xf0ff | (ushort)uVar10;
    bVar2 = *(byte *)(iVar6 + 4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar6 + iVar8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar6 + iVar8) = uVar3 & 0xefff | (ushort)bVar2 << 0xc;
  }
  return iVar7;
}

