/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_init_evt_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_start_init_evt_param(int param_1,int param_2)

{
  code cVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  void *__dest;
  short sVar6;
  byte bVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  *(code **)(iVar2 + 0x20) = r_lld_adv_evt_canceled_cbk_hack;
  *(code **)(iVar2 + 0x18) = r_lld_adv_evt_start_cbk;
  bVar7 = DAT_0001600d;
  cVar1 = r_assert_err;
  *(char *)(iVar2 + 0x87) = (char)param_1;
  *(code *)(iVar2 + 0x16) = cVar1;
  *(ushort *)(iVar2 + 0x14) = bVar7 & 0xf | 0x6000;
  uVar8 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 100) = uVar8;
  *(undefined2 *)(iVar2 + 0x74) = *(undefined2 *)(param_2 + 0x18);
  *(undefined1 *)(iVar2 + 0x8a) = *(undefined1 *)(param_2 + 0x26);
  memcpy((void *)(iVar2 + 0x2c),(void *)(param_2 + 6),6);
  *(undefined1 *)(iVar2 + 0x8b) = *(undefined1 *)(param_2 + 0x1e);
  *(undefined1 *)(iVar2 + 0x8c) = *(undefined1 *)(param_2 + 0x1f);
  *(undefined1 *)(iVar2 + 0x8d) = *(undefined1 *)(param_2 + 0x21);
  *(undefined1 *)(iVar2 + 0x8f) = *(undefined1 *)(param_2 + 0x23);
  bVar7 = *(byte *)(param_2 + 0x22);
  if ((bVar7 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar7 = bVar7 - 1;
  }
  *(byte *)(iVar2 + 0x8e) = bVar7;
  bVar7 = *(byte *)(param_2 + 0x24);
  if ((bVar7 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar7 = bVar7 - 1;
  }
  *(byte *)(iVar2 + 0x90) = bVar7;
  *(undefined *)(iVar2 + 0x93) =
       (&one_bits)[*(byte *)(param_2 + 0x1d) >> 4] + (&one_bits)[*(byte *)(param_2 + 0x1d) & 0xf];
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  *(ushort *)(iVar2 + 0x76) = *(ushort *)(iVar2 + 0x76) & 0xf000 | uVar3 & 0xfff;
  if ((*(byte *)(param_2 + 0x25) & 0xf0) != 0) {
    r_assert_param(0xf000,"lld_adv.c",0xbb5);
  }
  *(ushort *)(iVar2 + 0x76) =
       *(ushort *)(iVar2 + 0x76) & 0xfff | (ushort)*(byte *)(param_2 + 0x25) << 0xc;
  *(ushort *)(iVar2 + 0x78) = (ushort)*(byte *)(param_2 + 0x1c);
  *(undefined1 *)(iVar2 + 0x88) = 0xff;
  *(undefined2 *)(iVar2 + 0x82) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(iVar2 + 0x7e) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(iVar2 + 0x84) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(iVar2 + 0x80) = *(undefined2 *)(param_2 + 0x12);
  if ((*(ushort *)(iVar2 + 0x74) & 0x10) == 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar4 + 0x18) == '\0') {
      r_assert_err(0,"lld_adv.c",0xbc3);
    }
    *(bool *)(iVar2 + 0x95) = *(char *)(iVar2 + 0x8f) != '\0';
    r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar2 + 0x87));
    if (*(char *)(iVar2 + 0x95) == '\0') {
      return;
    }
    *(undefined4 *)(iVar2 + 0x54) = 0x10000;
    *(code **)(iVar2 + 0x4c) = r_lld_adv_aux_evt_start_cbk;
    cVar1 = r_emi_get_mem_addr_by_offset;
    *(undefined4 *)(iVar2 + 0x50) = 0;
    *(code *)(iVar2 + 0x4a) = cVar1;
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x10);
    *(ushort *)(iVar2 + 0x48) = DAT_00016011 & 0xf | 0x6000;
    return;
  }
  uVar9 = (uint)*(byte *)(iVar2 + 0x87) * 9 & 0xff;
  uVar10 = uVar9 + 1 & 0xff;
  switch(*(ushort *)(iVar2 + 0x74) - 0x10) {
  case 0:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x5b2 + -300 + (uint)_sdk_cfg_priv_opts;
    uVar3 = 2;
    break;
  default:
    r_assert_err(0,"lld_adv.c",0xbfc);
    goto _L1060;
  case 2:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    uVar3 = 6;
    break;
  case 3:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
_L1060:
    uVar3 = 0;
    break;
  case 5:
  case 0xd:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    uVar3 = 1;
    uVar14 = *(byte *)(param_2 + 0x1f) & 1;
    goto _L1025;
  }
  uVar14 = 0;
_L1025:
  iVar11 = uVar9 * 0xe;
  bVar7 = *(byte *)(param_2 + 0x1e);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar4 + iVar11 + 2) =
       (ushort)((bVar7 & 1) << 6) | (ushort)(uVar14 << 7) | uVar3 | 0x620;
  if ((*(ushort *)(iVar2 + 0x74) & 4) == 0) {
    if (*(ushort *)(param_2 + 0x14) == 0) {
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(undefined2 *)(iVar4 + iVar11 + 4) = 0;
      iVar4 = r_bt_rf_coex_st_param_get(2);
      if (iVar4 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [LDC] [EN%d] [%d] \n",*(undefined1 *)(iVar4 + 4),
                     *(undefined1 *)(iVar4 + 5));
        }
        uVar14 = (uint)*(byte *)(iVar4 + 5) << 8;
        if ((uVar14 & 0xf000) != 0) {
          r_assert_err(0,"lld_adv.c",0x33f);
        }
        iVar13 = iVar11 + 10;
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar5 + iVar13);
        iVar5 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar5 + iVar13) = uVar3 & 0xf0ff | (ushort)uVar14;
        bVar7 = *(byte *)(iVar4 + 4);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar4 + iVar13);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar13) = uVar3 & 0xefff | (ushort)bVar7 << 0xc;
      }
      goto _L1029;
    }
    sVar6 = *(short *)(param_2 + 0x10);
    uVar3 = *(ushort *)(param_2 + 0x14) & 0xff;
  }
  else {
    sVar6 = (ushort)*(byte *)(iVar2 + 0x87) * 0x4b + 0x2000;
    __dest = (void *)r_emi_get_mem_addr_by_offset(sVar6);
    memcpy(__dest,(void *)(param_2 + 6),6);
    uVar3 = 6;
  }
  r_lld_adv_adv_data_set(param_1,uVar3,sVar6,0,0);
_L1029:
  iVar5 = uVar10 * 0xe;
  bVar7 = *(byte *)(param_2 + 0x1e);
  iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar13 = iVar5 + 2;
  *(ushort *)(iVar4 + iVar13) = (ushort)((bVar7 & 1) << 6) | 4;
  if ((*(ushort *)(iVar2 + 0x74) & 4) == 0) {
    if (*(ushort *)(param_2 + 0x16) == 0) {
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar4 + iVar13);
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar4 + iVar13) = uVar3 & 0xff | 0x600;
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      *(undefined2 *)(iVar4 + iVar5 + 4) = 0;
      iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar3 = *(ushort *)(iVar4 + iVar5);
      iVar4 = r_emi_get_mem_addr_by_offset();
      *(ushort *)(iVar4 + iVar5) = (short)uVar9 * 0xe + 0x1400U | uVar3 & 0x8000;
      iVar4 = r_bt_rf_coex_st_param_get(2);
      if (iVar4 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [LDC ADV] [EN%d] [%d] \n",*(undefined1 *)(iVar4 + 4),
                     *(undefined1 *)(iVar4 + 5));
        }
        uVar9 = (uint)*(byte *)(iVar4 + 5) << 8;
        if ((uVar9 & 0xf000) != 0) {
          r_assert_err(0,"lld_adv.c",0x33f);
        }
        iVar12 = iVar5 + 10;
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar13 + iVar12);
        iVar13 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar13 + iVar12) = uVar3 & 0xf0ff | (ushort)uVar9;
        bVar7 = *(byte *)(iVar4 + 4);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar4 + iVar12);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar12) = uVar3 & 0xefff | (ushort)bVar7 << 0xc;
      }
    }
    else {
      r_lld_adv_scan_rsp_data_set
                (param_1,*(ushort *)(param_2 + 0x16) & 0xff,*(undefined2 *)(param_2 + 0x12),0,0);
    }
  }
  if ((*(ushort *)(iVar2 + 0x74) & 6) == 2) {
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar2 + iVar11);
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar2 + iVar11) = (short)uVar10 * 0xe + 0x1400U | uVar3 & 0x8000;
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar2 + iVar5);
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar2 + iVar5) = uVar3 & 0x7fff;
  }
  else {
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar3 = *(ushort *)(iVar2 + iVar11);
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar2 + iVar11) = uVar3 & 0x8000;
  }
  iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar3 = *(ushort *)(iVar2 + iVar11);
  iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar2 + iVar11) = uVar3 & 0x7fff;
  return;
}

