/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
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
  int iVar2;
  int *piVar3;
  size_t sVar4;
  
  if (param_1 != 1) {
    if (param_1 == 2) {
      DAT_000113a8 = DAT_000113a8 & ~param_2;
      if ((param_2 & 1) != 0) {
        llm_util_flush_list_part_0(&le_scan_duplicate_option);
      }
      if ((param_2 & 2) != 0) {
        llm_util_flush_list_part_0(&le_scan_duplicate_option);
      }
      goto _L69;
    }
    if (param_1 != 0) {
      return 0xc;
    }
    uVar1 = 0x12;
    if (param_3 == (void *)0x0) {
      return 0x12;
    }
    piVar3 = le_scan_duplicate_option;
    switch(param_2) {
    case 0:
      sVar4 = 6;
      goto _L70;
    case 1:
      sVar4 = 4;
_L70:
      for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
        iVar2 = memcmp(piVar3 + 1,param_3,sVar4);
        if (iVar2 == 0) goto _L69;
      }
      iVar2 = r_ke_malloc(0xc,0);
      if (iVar2 == 0) {
        return 7;
      }
      if (param_2 == 0) {
        memcpy((void *)(iVar2 + 4),param_3,6);
        r_co_list_push_front(&le_scan_duplicate_option,iVar2);
        DAT_000113a8 = DAT_000113a8 | 1;
      }
      else {
        memcpy((void *)(iVar2 + 4),param_3,4);
        r_co_list_push_front(&le_scan_duplicate_option,iVar2);
        DAT_000113a8 = DAT_000113a8 | 2;
      }
      break;
    case 2:
      DAT_000113a8 = DAT_000113a8 | 4;
      break;
    case 3:
      DAT_000113a8 = DAT_000113a8 | 8;
      break;
    case 4:
      DAT_000113a8 = DAT_000113a8 | 0x10;
      break;
    case 5:
      DAT_000113a8 = DAT_000113a8 | 0x20;
      break;
    case 6:
      DAT_000113a8 = DAT_000113a8 | 0x40;
      break;
    default:
      goto _L104;
    }
    goto _L69;
  }
  uVar1 = 0x12;
  if (param_3 == (void *)0x0) {
    return 0x12;
  }
  piVar3 = le_scan_duplicate_option;
  switch(param_2) {
  case 0:
    sVar4 = 6;
    goto _L83;
  case 1:
    sVar4 = 4;
_L83:
    for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      iVar2 = memcmp(piVar3 + 1,param_3,sVar4);
      if (iVar2 == 0) {
        r_co_list_extract(&le_scan_duplicate_option,piVar3);
        r_ke_free(piVar3);
        break;
      }
    }
    if (DAT_000113ac == 0) {
      DAT_000113a8 = DAT_000113a8 & 0xfffffffe;
    }
    if (DAT_000113b4 == 0) {
      DAT_000113a8 = DAT_000113a8 & 0xfffffffd;
    }
    break;
  case 2:
    DAT_000113a8 = DAT_000113a8 & 0xfffffffb;
    break;
  case 3:
    DAT_000113a8 = DAT_000113a8 & 0xfffffff7;
    break;
  case 4:
    DAT_000113a8 = DAT_000113a8 & 0xffffffef;
    break;
  case 5:
    DAT_000113a8 = DAT_000113a8 & 0xffffffdf;
    break;
  case 6:
    DAT_000113a8 = DAT_000113a8 & 0xffffffbf;
    break;
  default:
    goto _L104;
  }
_L69:
  uVar1 = 0;
_L104:
  return uVar1;
}

