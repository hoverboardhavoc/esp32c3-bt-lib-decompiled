/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_update_duplicate_scan_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_llm_update_duplicate_scan_exceptional_list(int param_1,uint param_2,void *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  size_t sVar6;
  
  if (param_1 != 1) {
    if (param_1 == 2) {
      le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ & ~param_2;
      if ((param_2 & 1) != 0) {
        llm_util_flush_list_part_0(0x11378);
      }
      if ((param_2 & 2) != 0) {
        llm_util_flush_list_part_0(0x11380);
      }
      goto _L109;
    }
    if (param_1 != 0) {
      return 0xc;
    }
    if (param_3 == (void *)0x0) {
_L104:
      return 0x12;
    }
    switch(param_2) {
    case 0:
      sVar6 = 6;
      piVar4 = (int *)(le_scan_duplicate_option + 0x2c);
      goto _L68;
    case 1:
      sVar6 = 4;
      piVar4 = (int *)(le_scan_duplicate_option + 0x34);
_L68:
      for (piVar4 = (int *)*piVar4; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        iVar3 = memcmp(piVar4 + 1,param_3,sVar6);
        if (iVar3 == 0) goto _L109;
      }
      iVar3 = r_ke_malloc(0xc,0);
      if (iVar3 == 0) {
        return 7;
      }
      if (param_2 == 0) {
        memcpy((void *)(iVar3 + 4),param_3,6);
        r_co_list_push_front(0x11378,iVar3);
        le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ | 1;
      }
      else {
        memcpy((void *)(iVar3 + 4),param_3,4);
        r_co_list_push_front(0x11380,iVar3);
        le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ | 2;
      }
      break;
    case 2:
      le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ | 4;
      break;
    case 3:
      le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ | 8;
      break;
    case 4:
      le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ | 0x10;
      break;
    case 5:
      le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ | 0x20;
      break;
    case 6:
      le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ | 0x40;
      break;
    default:
      goto _L104;
    }
    return 0;
  }
  uVar1 = 0x12;
  if (param_3 == (void *)0x0) {
    return 0x12;
  }
  switch(param_2) {
  case 0:
    sVar6 = 6;
    puVar5 = (undefined4 *)(le_scan_duplicate_option + 0x2c);
    goto _L81;
  case 1:
    sVar6 = 4;
    puVar5 = (undefined4 *)(le_scan_duplicate_option + 0x34);
_L81:
    for (puVar2 = (undefined4 *)*puVar5; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2
        ) {
      iVar3 = memcmp(puVar2 + 1,param_3,sVar6);
      if (iVar3 == 0) {
        r_co_list_extract(puVar5,puVar2);
        r_ke_free(puVar2);
        break;
      }
    }
    if (le_scan_duplicate_option._44_4_ == 0) {
      le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ & 0xfffffffe;
    }
    if (le_scan_duplicate_option._52_4_ == 0) {
      le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ & 0xfffffffd;
    }
    break;
  case 2:
    le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ & 0xfffffffb;
    break;
  case 3:
    le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ & 0xfffffff7;
    break;
  case 4:
    le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ & 0xffffffef;
    break;
  case 5:
    le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ & 0xffffffdf;
    break;
  case 6:
    le_scan_duplicate_option._40_4_ = le_scan_duplicate_option._40_4_ & 0xffffffbf;
    break;
  default:
    goto _L104;
  }
_L109:
  uVar1 = 0;
_L104:
  return uVar1;
}

