/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_debug_snap.o -> ble_debug_controller_snap
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_debug_controller_snap(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  ushort uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined4 *puVar12;
  char *pcVar13;
  short *psVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 uVar18;
  char *pcVar19;
  undefined4 extraout_a1;
  undefined4 uVar20;
  undefined4 uVar21;
  bool bVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  char *pcVar29;
  int *piVar30;
  int *piVar31;
  int *piVar32;
  int *piVar33;
  int *piVar34;
  int *piVar35;
  undefined4 uVar36;
  
  iVar15 = r_sdk_config_get_opts();
  bVar1 = *(byte *)(iVar15 + 0xd);
  uVar16 = r_rwip_time_get();
  ets_printf("\n>S %x.%d %d %d %d\n",uVar16,extraout_a1,*(undefined1 *)(_p_lld_env + 0xd8),
             *(undefined1 *)(_p_lld_env + 0xd9),*(undefined1 *)(_p_lld_env + 0xda));
  piVar31 = (int *)&lld_con_env;
  piVar33 = (int *)&lld_sync_env;
  piVar32 = (int *)&lld_per_adv_env;
  piVar34 = (int *)&lld_adv_env;
  piVar35 = (int *)&llc_env;
  piVar30 = (int *)&lld_con_env;
  iVar15 = 0;
  uVar26 = 0;
  do {
    uVar27 = uVar26 & 0xff;
    if (bVar1 <= uVar27) {
      iVar15 = 0;
      iVar28 = 0;
      ets_printf(">R %d %d\n",*(undefined1 *)(_p_lld_env + 0xd8),*(undefined1 *)(_p_lld_env + 0xd9))
      ;
      do {
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        sVar2 = *(short *)(iVar17 + iVar15);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar3 = *(ushort *)(iVar17 + 2 + iVar15);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar4 = *(undefined2 *)(iVar17 + 4 + iVar15);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(undefined2 *)(iVar17 + 6 + iVar15);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar6 = *(ushort *)(iVar17 + 0xc + iVar15);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar7 = *(ushort *)(iVar17 + 10 + iVar15);
        if ((uVar7 & 0xf000) != 0) {
          r_assert_err(0,"lld_debug_snap.c",1000);
        }
        iVar17 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar24 = CONCAT22(uVar7,*(undefined2 *)(iVar15 + 8 + iVar17));
        r_emi_get_mem_addr_by_offset(0x1000);
        uVar20 = 0x44;
        if (-1 < sVar2) {
          uVar20 = 0x5f;
        }
        snap_elapsed_ms(uVar16,uVar24);
        ets_printf(" %d:%c %02x %04x %04x %x %lx.%d(%ld)\n",iVar28,uVar20,uVar3 & 0xff,uVar4,uVar5,
                   uVar6 >> 0xb,uVar24);
        puVar12 = _p_ble_util_buf_env;
        iVar28 = iVar28 + 1;
        iVar15 = iVar15 + 0x14;
      } while (iVar28 != 10);
      if (_p_ble_util_buf_env != (undefined4 *)0x0) {
        uVar16 = snap_list_cnt_isra_0(*_p_ble_util_buf_env);
        uVar20 = snap_list_cnt_isra_0(puVar12[2]);
        uVar24 = snap_list_cnt_isra_0(puVar12[4]);
        uVar18 = snap_list_cnt_isra_0(puVar12[6]);
        ets_printf(">B %d/%d %d/%d %d/%d %d/%d\n",uVar16,0x14,uVar20,9,uVar24,0xc,uVar18);
      }
      uVar16 = snap_list_cnt_isra_0(_ke_env);
      uVar20 = snap_list_cnt_isra_0(_hci_tl_env);
      uVar24 = snap_list_cnt_isra_0(_lld_scan_env);
      ets_printf(">K %d %d %d\n",uVar16,uVar20,uVar24);
      uVar16 = snap_list_cnt_isra_0(_sch_arb_env);
      uVar20 = snap_list_cnt_isra_0(_lld_scan_env);
      ets_printf(">Q %d %d %d\n",uVar16,_r_lld_con_cntl_pkt_info_get != 0,uVar20);
      uVar16 = snap_list_cnt_isra_0(_hci_tl_env);
      ets_printf(">H %d",uVar16);
      uVar16 = snap_list_cnt_isra_0(_lld_scan_env);
      ets_printf(&__c_6,uVar16);
      ets_printf(&__c_5,(int)DAT_00011051);
      ets_printf(">D %08lx %08lx\n",_DAT_60031054,_DAT_60031054);
      pcVar19 = (char *)r_lld_con_cntl_pkt_info_get();
      psVar14 = (short *)(pcVar19 + 0x28);
      pcVar13 = &g_event_empty;
      bVar22 = false;
      pcVar29 = pcVar19;
      for (uVar26 = 0; (uVar26 & 0xff) < (uint)bVar1; uVar26 = uVar26 + 1) {
        if ((*piVar31 != 0) &&
           ((((*psVar14 != 0 || (*pcVar29 != '\0')) || (*(char *)((int)psVar14 + 0x15) != '\0')) ||
            (*pcVar13 != '\0')))) {
          if (!bVar22) {
            ets_printf(&__c_3);
          }
          ets_printf(" %d:%d %d %d %d %d",uVar26,*psVar14,*pcVar29,pcVar29[3],
                     *(char *)((int)psVar14 + 0x15),*pcVar13);
          bVar22 = true;
        }
        psVar14 = psVar14 + 1;
        pcVar29 = pcVar29 + 4;
        pcVar13 = pcVar13 + 1;
        piVar31 = piVar31 + 1;
      }
      if (bVar22) {
        ets_printf(" %lx\n",*(undefined4 *)(pcVar19 + 0x50));
      }
      ets_printf(&__c_0);
      return;
    }
    iVar28 = r_emi_get_mem_addr_by_offset(0x400);
    uVar3 = *(ushort *)(iVar28 + iVar15);
    if ((uVar3 & 0x1f) == 0) goto _L17;
    iVar28 = r_emi_get_mem_addr_by_offset(0x400);
    uVar4 = *(undefined2 *)(iVar15 + 2 + iVar28);
    iVar28 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = *(undefined2 *)(iVar15 + 0x18 + iVar28);
    iVar28 = r_emi_get_mem_addr_by_offset(0x400);
    uVar8 = *(undefined2 *)(iVar15 + 4 + iVar28);
    iVar28 = r_emi_get_mem_addr_by_offset(0x400);
    uVar9 = *(undefined2 *)(iVar15 + 0x16 + iVar28);
    iVar28 = r_emi_get_mem_addr_by_offset(0x400);
    ets_printf(">%d %x %04x %04x %04x %04x %04x\n",uVar26,uVar4,uVar5,uVar8,uVar9,
               *(undefined2 *)(iVar15 + 0x1c + iVar28));
    iVar28 = _lld_scan_env;
    switch((uVar3 & 0x1f) - 2 & 0xff) {
    case 0:
    case 1:
      iVar28 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(undefined2 *)(iVar15 + 0x22 + iVar28);
      iVar28 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(undefined2 *)(iVar15 + 0x50 + iVar28);
      iVar28 = r_emi_get_mem_addr_by_offset(0x400);
      uVar8 = *(undefined2 *)(iVar15 + 0x28 + iVar28);
      iVar28 = r_emi_get_mem_addr_by_offset(0x400);
      uVar9 = *(undefined2 *)(iVar15 + 0x2a + iVar28);
      iVar28 = r_emi_get_mem_addr_by_offset(0x400);
      uVar10 = *(undefined2 *)(iVar15 + 0x20 + iVar28);
      iVar28 = r_emi_get_mem_addr_by_offset(0x400);
      uVar11 = *(undefined2 *)(iVar15 + 0x1a + iVar28);
      iVar28 = r_emi_get_mem_addr_by_offset(0x400);
      ets_printf(" %04x %04x %04x %04x %04x %04x %04x\n",uVar4,uVar5,uVar8,uVar9,uVar10,uVar11,
                 *(undefined2 *)(iVar15 + 0x56 + iVar28));
      iVar28 = *piVar30;
      if (iVar28 == 0) break;
      uVar20 = 0x53;
      if ((*(ushort *)(iVar28 + 0x84) & 1) == 0) {
        uVar20 = 0x4d;
      }
      ets_printf(" C%d %c %d %lu %d %lu %d %d %d %d %04x\n",uVar26,uVar20,
                 *(undefined1 *)(iVar28 + 0x8f),*(undefined4 *)(iVar28 + 100),
                 *(undefined2 *)(iVar28 + 0x72),*(undefined4 *)(iVar28 + 0x68),
                 *(undefined2 *)(iVar28 + 0x7c));
      uVar20 = snap_list_cnt_isra_0(*(undefined4 *)(iVar28 + 0x28));
      ets_printf("  %d %d %d %d %d\n",*(undefined1 *)(iVar28 + 0x46),*(undefined2 *)(iVar28 + 0x44),
                 uVar20,*(int *)(iVar28 + 0x24) != 0,(&g_event_empty)[uVar26]);
      uVar36 = *(undefined4 *)(iVar28 + 0x48);
      uVar20 = snap_elapsed_ms(uVar16,uVar36);
      uVar21 = *(undefined4 *)(iVar28 + 0x54);
      uVar24 = snap_elapsed_ms(uVar16,uVar21);
      uVar23 = *(undefined4 *)(iVar28 + 0x50);
      uVar18 = snap_elapsed_ms(uVar16,uVar23);
      uVar25 = *(undefined4 *)(iVar28 + 0x58);
      snap_elapsed_ms(uVar16,uVar25);
      ets_printf("  %lx(%ld) %lx(%ld) %lx(%ld) %lx(%ld)\n",uVar36,uVar20,uVar21,uVar24,uVar23,uVar18
                 ,uVar25);
      uVar24 = *(undefined4 *)(iVar28 + 4);
      uVar20 = snap_elapsed_ms(uVar16);
      ets_printf("  %lx.%lu(%ld) %d %lu %d\n",uVar24,*(undefined4 *)(iVar28 + 8),uVar20,
                 (int)*(short *)(iVar28 + 0x6c),*(undefined4 *)(iVar28 + 0x4c),
                 *(undefined2 *)(iVar28 + 0x74));
      iVar28 = *piVar35;
      if (iVar28 != 0) {
        snap_list_cnt_isra_0(*(undefined4 *)(iVar28 + 0x28));
        ets_printf("  %d %d %d %d %d %d %04x %d %d\n",*(undefined2 *)(iVar28 + 0xe),
                   *(undefined2 *)(iVar28 + 0x10),*(undefined2 *)(iVar28 + 0x12),
                   *(undefined1 *)(iVar28 + 0x1c),*(undefined1 *)(iVar28 + 0x1d),
                   *(undefined1 *)(iVar28 + 0x44),*(undefined2 *)(iVar28 + 0x42));
      }
      uVar20 = 2;
      goto _L80;
    case 2:
    case 3:
    case 4:
      iVar28 = *piVar34;
      if (iVar28 != 0) {
        snap_elapsed_ms(uVar16);
        ets_printf(" V%d %d %04x %lu %d %d %d %d %d %lx(%ld)\n",uVar26,
                   *(undefined1 *)(iVar28 + 0x89),*(undefined2 *)(iVar28 + 0x74),
                   *(undefined4 *)(iVar28 + 100),*(undefined2 *)(iVar28 + 0x82),
                   *(undefined2 *)(iVar28 + 0x84),(int)*(char *)(iVar28 + 0x8d));
        if (*(char *)(iVar28 + 0x92) != '\0') {
          snap_dump_txdesc_part_0(uVar27);
        }
      }
      iVar28 = *piVar32;
      if (iVar28 != 0) {
        ets_printf(" P%d %d %lu %d %d %d %d\n",uVar26,*(undefined1 *)(iVar28 + 0x53),
                   *(undefined4 *)(iVar28 + 0x40),*(undefined2 *)(iVar28 + 0x4c),
                   (int)*(char *)(iVar28 + 0x56),*(undefined1 *)(iVar28 + 0x55),
                   *(undefined1 *)(iVar28 + 0x58));
      }
      break;
    default:
      ets_printf(__c_14,uVar26);
      break;
    case 6:
    case 7:
    case 8:
    case 9:
      if ((_lld_scan_env != 0) && (*(byte *)(_lld_scan_env + 0xd) == uVar27)) {
        uVar24 = *(undefined4 *)(_lld_scan_env + 8);
        uVar20 = snap_elapsed_ms(uVar16,uVar24);
        ets_printf(" S%d %x %d %lx(%ld)\n",uVar26,*(undefined1 *)(iVar28 + 0xc),
                   *(undefined1 *)(iVar28 + 0x15),uVar24,uVar20);
      }
      goto _L33;
    case 0xc:
    case 0xd:
      ets_printf(" I%d\n",uVar26);
_L33:
      uVar20 = 1;
_L80:
      snap_dump_txdesc_part_0(uVar27,uVar20);
      break;
    case 0x1a:
    case 0x1b:
    case 0x1c:
      ets_printf(" X%d\n",uVar26);
    }
    iVar28 = *piVar33;
    if (iVar28 != 0) {
      uVar20 = *(undefined4 *)(iVar28 + 4);
      snap_elapsed_ms(uVar16,uVar20);
      snap_elapsed_ms(uVar16);
      ets_printf(" Y%d %d %d %d %d %lu %lx(%ld) %lx(%ld)\n",uVar26,*(undefined1 *)(iVar28 + 0x5b),
                 *(undefined1 *)(iVar28 + 0x59),*(undefined2 *)(iVar28 + 0x4a),
                 *(undefined1 *)(iVar28 + 0x57),*(undefined4 *)(iVar28 + 0x40),uVar20);
    }
_L17:
    uVar26 = uVar26 + 1;
    piVar33 = piVar33 + 1;
    piVar32 = piVar32 + 1;
    piVar34 = piVar34 + 1;
    iVar15 = iVar15 + 0x5a;
    piVar30 = piVar30 + 1;
    piVar35 = piVar35 + 1;
  } while( true );
}

