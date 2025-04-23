/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm.o -> r_llm_update_duplicate_scan_exceptional_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_update_duplicate_scan_exceptional_list(int param_1,uint param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  uint uVar7;
  size_t sVar8;
  
  if (param_1 == 1) {
    if (param_3 == (void *)0x0) {
_L65:
      return 0x12;
    }
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
    switch(param_2) {
    case 0:
      piVar6 = (int *)(iVar2 + 0x2c);
      sVar8 = 6;
      goto _L90;
    case 1:
      piVar6 = (int *)(iVar2 + 0x34);
      sVar8 = 4;
_L90:
      for (piVar1 = (int *)*piVar6; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
        iVar4 = memcmp(piVar1 + 1,param_3,sVar8);
        if (iVar4 == 0) {
          (**(code **)(_r_modules_funcs_p + 0x1c))
                    (piVar6,piVar1,*(code **)(_r_modules_funcs_p + 0x1c));
          (**(code **)(_r_modules_funcs_p + 0x110))(piVar1,*(code **)(_r_modules_funcs_p + 0x110));
          break;
        }
      }
      if (*(int *)(iVar2 + 0x2c) == 0) {
        *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) & 0xfffffffe;
      }
      if (*(int *)(iVar2 + 0x34) != 0) {
        return 0;
      }
      uVar7 = *(uint *)(iVar2 + 0x28) & 0xfffffffd;
      break;
    case 2:
      uVar7 = *(uint *)(iVar2 + 0x28) & 0xfffffffb;
      break;
    case 3:
      uVar7 = *(uint *)(iVar2 + 0x28) & 0xfffffff7;
      break;
    case 4:
      uVar7 = *(uint *)(iVar2 + 0x28) & 0xffffffef;
      break;
    case 5:
      uVar7 = *(uint *)(iVar2 + 0x28) & 0xffffffdf;
      break;
    case 6:
      uVar7 = *(uint *)(iVar2 + 0x28) & 0xffffffbf;
      break;
    default:
      goto _L65;
    }
    goto _L119;
  }
  if (param_1 == 2) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924));
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) & ~param_2;
    if ((param_2 & 1) != 0) {
      llm_util_flush_list(iVar2 + 0x2c);
    }
    if ((param_2 & 2) == 0) {
      return 0;
    }
    llm_util_flush_list(iVar2 + 0x34);
    return 0;
  }
  if (param_1 != 0) {
    return 0xc;
  }
  if (param_3 == (void *)0x0) {
    return 0x12;
  }
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x924))(0xc,*(code **)(_r_ip_funcs_p + 0x924));
  switch(param_2) {
  case 0:
    piVar6 = (int *)(iVar2 + 0x2c);
    sVar8 = 6;
    goto _L75;
  case 1:
    piVar6 = (int *)(iVar2 + 0x34);
    sVar8 = 4;
_L75:
    for (piVar6 = (int *)*piVar6; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      iVar4 = memcmp(piVar6 + 1,param_3,sVar8);
      if (iVar4 == 0) {
        return 0;
      }
    }
    iVar3 = (**(code **)(_r_modules_funcs_p + 0x120))(0xc,0,*(code **)(_r_modules_funcs_p + 0x120));
    iVar4 = _r_modules_funcs_p;
    if (iVar3 == 0) {
      return 7;
    }
    if (param_2 == 0) {
      memcpy((void *)(iVar3 + 4),param_3,6);
      pcVar5 = *(code **)(iVar4 + 0x4c);
      (*pcVar5)(iVar2 + 0x2c,iVar3,pcVar5);
      uVar7 = *(uint *)(iVar2 + 0x28) | 1;
    }
    else {
      memcpy((void *)(iVar3 + 4),param_3,4);
      pcVar5 = *(code **)(iVar4 + 0x4c);
      (*pcVar5)(iVar2 + 0x34,iVar3,pcVar5);
      uVar7 = *(uint *)(iVar2 + 0x28) | 2;
    }
    break;
  case 2:
    uVar7 = *(uint *)(iVar2 + 0x28) | 4;
    break;
  case 3:
    uVar7 = *(uint *)(iVar2 + 0x28) | 8;
    break;
  case 4:
    uVar7 = *(uint *)(iVar2 + 0x28) | 0x10;
    break;
  case 5:
    uVar7 = *(uint *)(iVar2 + 0x28) | 0x20;
    break;
  case 6:
    uVar7 = *(uint *)(iVar2 + 0x28) | 0x40;
    break;
  default:
    goto _L65;
  }
_L119:
  *(uint *)(iVar2 + 0x28) = uVar7;
  return 0;
}

