/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
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
  char *pcVar8;
  void *__dest;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  ushort *in_stack_00000000;
  int iStack_5c;
  undefined2 uStack_4c;
  undefined1 auStack_4a [5];
  undefined1 uStack_45;
  undefined1 uStack_44;
  
  iVar12 = param_2 * 0xe;
  iVar6 = *(int *)(&lld_per_adv_env + param_1 * 4);
  iVar15 = (uint)*(byte *)(iVar6 + 0x52) * 9;
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = *(ushort *)(iVar7 + iVar12);
  iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar7 + iVar12) = uVar3 & 0x8000;
  if (param_5 == 0) {
    iVar13 = 0;
    iVar7 = 0;
    if (param_2 != iVar15) goto _L118;
    iVar7 = 1;
  }
  else {
    iVar13 = 2;
    iVar7 = 2;
    if (param_2 != iVar15) goto _L118;
    iVar7 = 2;
  }
  iVar7 = iVar7 + 9;
_L118:
  if ((uint)*in_stack_00000000 + iVar7 < 0xff) {
    iStack_5c = 0;
    sVar5 = 0;
  }
  else {
    iVar10 = 2;
    if (iVar13 == 0) {
      if (iVar7 == 0) {
        iVar7 = 1;
      }
      iVar10 = 1;
    }
    iVar7 = iVar7 + 3;
    iVar13 = iVar10 + 3;
    iStack_5c = 1;
    sVar5 = 3;
  }
  if (param_5 != 0) {
    cVar1 = *(char *)(iVar6 + 0x56);
    iVar10 = r_llm_tx_path_comp_get();
    pcVar8 = (char *)r_emi_get_mem_addr_by_offset(*param_6 + sVar5);
    sVar5 = sVar5 + 1;
    *pcVar8 = cVar1 + (char)(iVar10 / 10);
  }
  if (param_2 == iVar15) {
    *(char *)(iVar6 + 0x59) = (char)sVar5;
    uStack_4c = 0x2808;
    memcpy(auStack_4a,(void *)(iVar6 + 0x2f),5);
    uStack_45 = (undefined1)*(undefined2 *)(iVar6 + 0x3a);
    uStack_44 = (undefined1)((ushort)*(undefined2 *)(iVar6 + 0x3a) >> 8);
    __dest = (void *)r_emi_get_mem_addr_by_offset(*param_6 + sVar5);
    sVar5 = sVar5 + 9;
    memcpy(__dest,&uStack_4c,9);
  }
  uVar14 = 0;
  uVar11 = (uint)*in_stack_00000000;
  if (uVar11 != 0) {
    uVar14 = -iVar7 - 2U & 0xff;
    if (uVar11 < uVar14) {
      uVar14 = uVar11 & 0xff;
    }
    *in_stack_00000000 = *in_stack_00000000 - (short)uVar14;
  }
  if ((param_4 << 6 & 0xffffff3fU) != 0) {
    r_assert_err(0,0x10000,500);
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar12 + 6 + iVar10) =
       (ushort)(param_5 << 0xe) | (ushort)(param_4 << 6) | (ushort)iVar13 |
       (ushort)(iStack_5c << 0xc);
  iVar7 = r_co_ble_pkt_dur_in_us(uVar14 + iVar7 + 1 & 0xff,*(undefined1 *)(iVar6 + 0x55));
  iVar10 = 0;
  if (iStack_5c != 0) {
    iVar10 = (iVar7 + 300U) / 0x1e + 1;
    iVar7 = iVar10 * 0x1e;
    *(short *)(iVar6 + 0x4a) = (short)iVar10;
  }
  bVar2 = *(byte *)(iVar6 + 0x57);
  uVar3 = *(ushort *)(_p_lld_env + 0xd4);
  if ((bVar2 & 0xc0) != 0) {
    r_assert_err(0,0x10000,0x2b0);
  }
  iVar9 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar12 + 8 + iVar9) =
       (ushort)(uVar3 < 0x33) << 6 | (ushort)bVar2 | (ushort)(iVar10 << 8);
  uVar11 = (uint)*(byte *)(iVar6 + 0x55) << 5;
  uVar3 = *(ushort *)(iVar6 + 0x4a) >> 8;
  if ((uVar11 & 0xffffff1f) != 0) {
    r_assert_err(0,0x10000,0x31c);
  }
  if ((uVar3 & 0xffe0) != 0) {
    r_assert_err(0,0x10000,0x31d);
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar9 = iVar12 + 10;
  *(ushort *)(iVar10 + iVar9) = uVar3 | (ushort)uVar11;
  sVar4 = *param_6;
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar12 + 0xc + iVar10) = sVar4;
  *param_6 = *param_6 + sVar5;
  if ((param_3 & 0xfffffff0) != 0) {
    r_assert_err(0,0x10000,0x126);
  }
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar12 + 2 + iVar10) =
       (ushort)((iVar13 + 1 + uVar14 & 0xff) << 8) | (ushort)param_3 | 0x20;
  sVar5 = *param_7;
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(short *)(iVar12 + 4 + iVar10) = sVar5;
  *param_7 = *param_7 + (short)uVar14;
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = *(ushort *)(iVar10 + iVar12);
  iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar10 + iVar12) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
  if (param_2 == iVar15) {
    *(char *)(iVar6 + 0x5a) = (char)iVar13;
    *(char *)(iVar6 + 0x5b) = (char)uVar14;
  }
  iVar6 = r_bt_rf_coex_st_param_get(4);
  if (iVar6 != 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("TX PTI [PER ADV DATA] [EN%d] [%d] \n",*(undefined1 *)(iVar6 + 4),
                 *(undefined1 *)(iVar6 + 5));
    }
    uVar11 = (uint)*(byte *)(iVar6 + 5) << 8;
    if ((uVar11 & 0xf000) != 0) {
      r_assert_err(0,0x10000,0x33f);
    }
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar12 + iVar9);
    iVar12 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar12 + iVar9) = uVar3 & 0xf0ff | (ushort)uVar11;
    bVar2 = *(byte *)(iVar6 + 4);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar6 + iVar9);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar9 + iVar6) = uVar3 & 0xefff | (ushort)bVar2 << 0xc;
  }
  return iVar7;
}

